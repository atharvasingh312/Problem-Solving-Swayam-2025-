//https://leetcode.com/problems/course-schedule/


class Solution {
public:
    bool dfs(int i,vector<vector<int>>& adj,vector<int>& vis,vector<int>& path)
    {
        if(path[i]) return 1;
        vis[i]=1;
        path[i]=1;
        for(auto x:adj[i])
        {
            if(!vis[x]) 
            {
                if(dfs(x,adj,vis,path))
                return 1;
            }
            else if(path[x]) return 1;  //again visited the node in path
        }
        path[i]=0;
        return 0;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n,vector<int>());
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> vis(n,0);
        vector<int> path(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            if(dfs(i,adj,vis,path)) 
            return 0;
        }
        return 1;
    }
};
