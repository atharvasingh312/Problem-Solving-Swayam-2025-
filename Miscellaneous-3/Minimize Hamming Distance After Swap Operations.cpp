//https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/


class DSU{
    vector<int> par,siz;
    public:
    DSU(int n){
        par.resize(n+1);
        siz.resize(n+1,1);
        for(int i=0;i<=n;i++){
            par[i]=i;
        }
    }
    int findpar(int u){
        if(par[u]==u) return u;
        return par[u]=findpar(par[u]);
    }
    void uni(int u,int v){
        int pu=findpar(u);
        int pv=findpar(v);
        if(pu==pv) return;
        if(siz[pu]<=siz[pv]){
            siz[pu]+=siz[pv];
            par[pv]=pu;
        }
        else{
            siz[pv]+=siz[pu];
            par[pu]=pv;
        }
    }
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        unordered_map<int,unordered_set<int>> mp;
        int n=target.size();
        for(int i=0;i<target.size();i++){
            mp[target[i]].insert(i);
        }
        DSU s(n+1);
        for(int i=0;i<allowedSwaps.size();i++){
            s.uni(allowedSwaps[i][0],allowedSwaps[i][1]);
        }
        int c=0;
        for(int i=0;i<source.size();i++){
            if(mp.find(source[i])!=mp.end()){
                int f=1,y=0;
                for(auto x:mp[source[i]]){
                    if(s.findpar(x)==s.findpar(i))
                    {
                        y=x;
                        f=0;
                        break;
                    }
                } 
                if(f) c++;
                else  mp[source[i]].erase(y);
            }
            else c++;
        }
        return c;
    }
};
