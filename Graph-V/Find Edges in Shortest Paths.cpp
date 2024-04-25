//https://leetcode.com/problems/find-edges-in-shortest-paths/description/

class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int> dist1(n,INT_MAX),dist2(n,INT_MAX);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0});
        dist1[0]=0;
        while(!pq.empty()){
            int node=pq.top()[1];
            int d=pq.top()[0];
            pq.pop();
            for(auto x:adj[node]){
                if(dist1[x[0]]>dist1[node]+x[1]){
                   dist1[x[0]]=dist1[node]+x[1];
                   pq.push({dist1[x[0]],x[0]}); 
                }
            }
        }
        pq.push({0,n-1});
        dist2[n-1]=0;
        while(!pq.empty()){
            int node=pq.top()[1];
            int d=pq.top()[0];
            pq.pop();
            for(auto x:adj[node]){
                if(dist2[x[0]]>dist2[node]+x[1]){
                   dist2[x[0]]=dist2[node]+x[1];
                   pq.push({dist1[x[0]],x[0]}); 
                }
            }
        }
        vector<bool> ans(edges.size(),0);
        for(int i=0;i<edges.size();i++)
        {
            if(dist1[edges[i][0]]!=INT_MAX && dist2[edges[i][1]]!=INT_MAX && dist1[n-1]==dist1[edges[i][0]]+edges[i][2]+dist2[edges[i][1]])
            ans[i]=1;
            if(dist1[edges[i][1]]!=INT_MAX && dist2[edges[i][0]]!=INT_MAX && dist1[n-1]==dist1[edges[i][1]]+edges[i][2]+dist2[edges[i][0]])
            ans[i]=1;
        }
        return ans;
    }
};
