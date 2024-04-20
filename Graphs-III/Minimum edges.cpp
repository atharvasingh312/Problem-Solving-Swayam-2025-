//https://www.geeksforgeeks.org/problems/minimum-edges/1


class Solution{
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            //using 0-1 BFS
            deque<pair<int,int>> q;
            vector<int> dis(n+1,INT_MAX);
            vector<vector<pair<int,int>>> adj(n+1);
            for(int i=0;i<edges.size();i++)
            {
                adj[edges[i][0]].push_back({edges[i][1],0});
                adj[edges[i][1]].push_back({edges[i][0],1});
            }
            q.push_back({0,src});
            dis[src]=0;
            while(!q.empty()){
                int d=q.front().first;
                int node=q.front().second;
                if(node==dst) return d;
                q.pop_front();
                for(auto x:adj[node]){
                    if(d+x.second<dis[x.first]){
                        dis[x.first]=d+x.second;
                        if(x.second==0)
                        q.push_front({d+x.second,x.first});
                        else
                        q.push_back({d+x.second,x.first});
                    }
                }
            }
            return -1;
        }
};
