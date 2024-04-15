//https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int s,vector<int> *adj,vector<int> &vis,vector<int> &path){
        vis[s]=1;
        path[s]=1;
        for(auto x:adj[s]){
            if(!vis[x]){ 
                if(dfs(x,adj,vis,path)) 
                return true;
            }
            else if(path[x]==1) return true;
        }
        path[s]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> path(V,0);
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path)) return true;
            }
        }
        return false;
    }
};
