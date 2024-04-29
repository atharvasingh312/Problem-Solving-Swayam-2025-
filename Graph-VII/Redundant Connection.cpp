//https://leetcode.com/problems/redundant-connection/


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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet s(edges.size());
        for(int i=0;i<edges.size();i++){
            if(s.findpar(edges[i][0])==s.findpar(edges[i][1])) return edges[i];
            s.uni(edges[i][0],edges[i][1]);
        }
        return {};
    }
};
