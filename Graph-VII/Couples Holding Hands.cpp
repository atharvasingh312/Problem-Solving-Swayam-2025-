//https://leetcode.com/problems/couples-holding-hands/

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
    int minSwapsCouples(vector<int>& row) {
        DisjointSet s(row.size());
        for(int i=0;i+1<row.size();i+=2)
        {
            s.uni(row[i],row[i+1]);
        }
        int c=0;
        for(int i=0;i<row.size();i+=2){
            if(s.findpar(i)!=s.findpar(i+1)){
                c++;
                s.uni(i,i+1);
            }
        }
        return c;
    }
};
