//https://leetcode.com/problems/minimum-time-to-visit-disappearing-nodes/


class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<pair<int,int>> adj[n];
        vector<int> dis(n,INT_MAX);
        for(int i=0;i<edges.size();i++){
             adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
             adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        pq.push({0,0});
        dis[0]=0;
        while(!pq.empty()){
            int f=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            if(d>dis[f]) continue;
            for(auto x:adj[f]){
                if(dis[x.first]>=d+x.second && disappear[x.first]>d+x.second){
                    dis[x.first]=d+x.second;
                    pq.push({dis[x.first],x.first});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dis[i]>=disappear[i]) dis[i]=-1;
        }
        return dis;
    }
};
