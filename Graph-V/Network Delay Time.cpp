//https://leetcode.com/problems/network-delay-time/description/


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> dist(n,INT_MAX);
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        pq.push({0,k-1});
        dist[k-1]=0;
        while(!pq.empty())
        {
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            for(auto x:adj[node])
            {
                if(dist[x.first]>d+x.second)
                {
                    dist[x.first]=d+x.second;
                    pq.push({dist[x.first],x.first});
                }
            }
        }
        int mx=INT_MIN;
        for(auto x:dist) mx=max(mx,x);
        if(mx==INT_MAX) return -1;
        return mx;
    }
};
