//https://leetcode.com/problems/largest-color-value-in-a-directed-graph/


class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        stack<int> st;
        int n=colors.size();
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][1]].push_back(edges[i][0]);//need to consider reverse
            indeg[edges[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        vector<unordered_map<int,int>> vmp(n);
        while(!q.empty()){
            int f=q.front();
            q.pop();
            vmp[f][colors[f]-'a']++;
            for(auto x:adj[f]){
                for(auto y:vmp[f]){
                  vmp[x][y.first]=max(vmp[x][y.first],y.second);  
                }
                indeg[x]--;
                if(indeg[x]==0) q.push(x);
            }
        }
        for(auto x:indeg)
        if(x!=0) return -1;//cycle
        int mx=-1;
        for(int i=0;i<n;i++){
            for(auto x:vmp[i]){
                mx=max(mx,x.second);
            }
        }
        return mx;
    }
};
