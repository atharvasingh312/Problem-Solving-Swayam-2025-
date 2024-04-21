//https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool bfs(vector<vector<int>>& graph,vector<int> & vis,int i)
    {
        int c=0;
        queue<int> q;
        vis[i]=c;
        q.push(i);
        while(!q.empty())
        {
            int s=q.size();
            c=(c+1)%2;
            for(int i=0;i<s;i++)
            {
                int n=q.front();
                q.pop();
                for(auto x:graph[n])
                {
                    if(vis[x]==-1)
                    {
                        vis[x]=c;
                        q.push(x);
                    }
                    else if(c!=vis[x]) return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                if(!bfs(graph,vis,i)) return false;
            }
        }
        return true;
    }
};
