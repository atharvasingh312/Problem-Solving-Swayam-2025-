//https://leetcode.com/problems/shortest-cycle-in-a-graph/


class Solution {
public:
    int bfs(int s,int d,vector<unordered_set<int>> &adj){
        queue<int> q;
        vector<int> vis(adj.size(),0);
        vis[s]=1;
        q.push(s);
        int l=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int f=q.front();
                q.pop();
                if(f==d) return l;
                for(auto x:adj[f]){
                    if(!vis[x]){
                        vis[x]=1;
                        q.push(x);
                    }
                }
            }
            l++;
        }
        return INT_MAX;
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n);
        for(auto x:edges)
        {
            adj[x[0]].insert(x[1]);
            adj[x[1]].insert(x[0]);
        }
        int mn=INT_MAX;
        for(int i=0;i<edges.size();i++)
        {
            int a=edges[i][0],b=edges[i][1];
            adj[a].erase(b);
            adj[b].erase(a);
            mn=min(mn,bfs(a,b,adj));
            adj[a].insert(b);
            adj[b].insert(a);
        }
        if(mn==INT_MAX) return -1;
        return mn;
    }
};
