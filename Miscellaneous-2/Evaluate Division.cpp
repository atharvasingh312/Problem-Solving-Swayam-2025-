//https://leetcode.com/problems/evaluate-division/


class Solution {
public:
    double dfs(int s,int d,double p,vector<vector<double>> adj,vector<int> &vis)
    {
        double ans=-1;
        if(s==d) return p;
        vis[s]=1;
        for(int i=0;i<adj.size();i++)
        {
            if(adj[s][i]==0) continue;
            if(vis[i]==-1)
            {
                vis[i]=1;
                ans=dfs(i,d,p*adj[s][i],adj,vis);
                if(ans!=-1) return ans;
            }
        }
        return ans;   
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> mp;
        int x=0;
        for(int i=0;i<equations.size();i++)
        {
            if(mp.find(equations[i][0])==mp.end()){
                mp[equations[i][0]]=x;
                x++;
            }
            if(mp.find(equations[i][1])==mp.end()){
                mp[equations[i][1]]=x;
                x++;
            }
        }
        int n=mp.size();
        vector<vector<double>> adj(n,vector<double>(n,0));
        for(int i=0;i<equations.size();i++)
        {
            int s=mp[equations[i][0]];
            int d=mp[equations[i][1]];
            adj[s][d]=values[i];
            adj[s][s]=1;
            adj[d][d]=1;
            adj[d][s]=(1/values[i]);
        }
        vector<double> ans;
        for(int i=0;i<queries.size();i++)
        {
            if(mp.find(queries[i][0])==mp.end()
            || mp.find(queries[i][1])==mp.end()){
                ans.push_back(-1);
            }
            else{
                vector<int> vis(n,-1);
                int s=mp[queries[i][0]];
                int d=mp[queries[i][1]];
                ans.push_back(dfs(s,d,1,adj,vis));
            }
        }
        return ans;
    }
};
