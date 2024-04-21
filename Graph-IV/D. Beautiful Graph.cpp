//https://codeforces.com/problemset/problem/1093/D


#include <bits/stdc++.h>
using namespace std;
#define int long long
int power(int a,int b,int mod){
    if(b==0) return 1;
    if(b==1){
        return a;
    }
    if(b%2==0){
        return power((a*a)%mod,b/2,mod);
    }
    else return (a*power(a,b-1,mod))%mod;
}
int solve(int s,vector<int> &col,vector<vector<int>> &adj)
{
    int mod=998244353;
    int f=1,c=0,tc=0;
    queue<int> q;
    q.push(s);
    col[s]=f;
    c++;
    while(!q.empty()){
        int sz=q.size();
        f=(f+1)%2;
        while(sz--){
            int fr=q.front();
            q.pop();
            tc++;
            for(auto x:adj[fr]){
                if(col[x]==-1){
                    if(f) c++;
                    col[x]=f;
                    q.push(x);
                }
                else if(col[x]!=f) return 0;
            }
        }
    }
    return (power(2,c,mod)%mod+power(2,tc-c,mod)%mod)%mod;
}
signed main()
{
    int mod=998244353;
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> adj(n+1);
        vector<int> col(n+1,-1);//0 for 2 and 1 for 1 and 3
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int c=1;
        for(int i=1;i<=n;i++){
            if(col[i]==-1){
                c=(c*solve(i,col,adj))%mod;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}
