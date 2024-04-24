//https://leetcode.com/problems/cheapest-flights-within-k-stops/


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> dist(n,INT_MAX);
        queue<vector<int>> pq;
        pq.push({0,0,src});
        dist[src]=0;
        while(!pq.empty()){
            int d=pq.front()[0];
            int s=pq.front()[2];
            int l=pq.front()[1];//path with more distance but less stops
            pq.pop();
            for(auto x:adj[s]){
                if((l<=k && dist[x.first]>x.second+d)){
                    dist[x.first]=x.second+d;
                    pq.push({dist[x.first],l+1,x.first});
                }
            }
        }
        if(dist[dst]==INT_MAX)  return -1;
        else                    return dist[dst];
    }
};
