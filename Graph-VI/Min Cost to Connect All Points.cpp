//https://leetcode.com/problems/min-cost-to-connect-all-points/


class DisjointSet
{
    vector<int> size,par;
    public:
    DisjointSet(int n)
    {
        size.resize(n+1,1);
        par.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            par[i]=i;
        }
    }
    int findpar(int u)
    {
        if(u==par[u]) return u;
        return par[u]=findpar(par[u]);
    }
    void uni(int u,int v)
    {
        int pu=findpar(u),pv=findpar(v);
        if(pu==pv) return;
        if(size[pu]<=size[pv])
        {
            par[pu]=pv;
            size[pv]+=size[pu];
        }
        else
        {
            par[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                pq.push({dis,i,j});
            }
        }
        DisjointSet s=DisjointSet(points.size());
        int ans=0;
        while(!pq.empty()){
            int d=pq.top()[0];
            int u=pq.top()[1];
            int v=pq.top()[2];
            if(s.findpar(u)!=s.findpar(v)){
                ans+=d;
                s.uni(u,v);
            }
            pq.pop();
        }
        return ans; 
    }
};
