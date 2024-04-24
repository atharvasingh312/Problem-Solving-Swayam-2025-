//https://leetcode.com/problems/redundant-connection-ii/description/


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
    void findcycle(vector<vector<int>> &adj,int st,vector<int> &path,vector<int> &vis,vector<int> &ans){
        vis[st]=1;
        path[st]=1;
        for(auto x:adj[st]){
            if(!vis[x]){
                findcycle(adj,x,path,vis,ans);
            }
            else if(path[x]!=-1 && ans.size()==0){
                ans.push_back(st);
                ans.push_back(x);
            }
        }
        path[st]=-1;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size()+1);
        unordered_set<int> st;
        int start=-1,loc=0;;
        vector<int> ans,path(edges.size()+1,-1),vis(edges.size()+1,0);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            if(st.find(edges[i][1])!=st.end())
            {
                if(start==-1)
                start=edges[i][1];
                loc=i;
            }
            st.insert(edges[i][1]);
        }
        //now if 2 parents there one needs to be removed
        //if no cycle last ocurance remove
        if(start!=-1){
            findcycle(adj,start,path,vis,ans);
            if(ans.size()!=0) return ans;
            else              return edges[loc];
        }
        DisjointSet s=DisjointSet(edges.size());
        for(int i=0;i<edges.size();i++)
        {
            if(s.findpar(edges[i][0])!=s.findpar(edges[i][1])){
                s.uni(edges[i][1],edges[i][0]);
            }
            else ans=edges[i];
        }
        return ans;
    }
};
