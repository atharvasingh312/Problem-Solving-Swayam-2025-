//https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/

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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet a=DisjointSet(n),b=DisjointSet(n);
        int ans=0;
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==3){
                if(a.findpar(edges[i][1])==a.findpar(edges[i][2])) ans++;
                else{
                    a.uni(edges[i][1],edges[i][2]);
                    b.uni(edges[i][1],edges[i][2]);
                }
            }
        }
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==1){
                if(a.findpar(edges[i][1])==a.findpar(edges[i][2])) ans++;
                else a.uni(edges[i][1],edges[i][2]);
            }
            if(edges[i][0]==2){
                if(b.findpar(edges[i][1])==b.findpar(edges[i][2])) ans++;
                else b.uni(edges[i][1],edges[i][2]);
            }
        }
        int ulp1=a.findpar(1),ulp2=b.findpar(1);
        for(int i=1;i<=n;i++){
            if(a.findpar(i)!=ulp1 || b.findpar(i)!=ulp2) return -1;
        }
        return ans;
    }
};
