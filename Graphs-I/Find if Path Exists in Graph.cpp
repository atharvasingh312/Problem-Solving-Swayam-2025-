//https://leetcode.com/problems/find-if-path-exists-in-graph/description/

class Solution {
public:
    void dfs(vector<vector<int>> &adj,vector<int> &vis,int s){
        vis[s]=1;
        for(auto x:adj[s]){
            if(!vis[x])
            dfs(adj,vis,x);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n,0);
        dfs(adj,vis,source);
        if(!vis[destination]) return false;
        return true;
    }
};
