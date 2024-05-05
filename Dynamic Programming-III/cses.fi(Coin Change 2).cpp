//https://cses.fi/problemset/view/1636/


#include<bits/stdc++.h>
using namespace std;
 
//recursion and memoization:
/*long long solve(int i,int x,vector<int> &coins,vector<vector<int>> &dp){
    int mod=(int)(1e9+7);
    if(x==0) return 1;
    else if(i==(int)coins.size()) return 0;
    else if(dp[i][x]!=-1) return dp[i][x];
    long long p=0;
    if(x-coins[i]>=0){
        p=(p+solve(i,x-coins[i],coins,dp))%mod;
    }
    return dp[i][x]=(p+solve(i+1,x,coins,dp))%mod;
}*/
int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> coins(n,0);
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int mod=(int)(1e9+7);
    //int ans=solve(0,x,coins,dp);
    //cout<<ans<<endl;
    for(int i=0;i<=n;i++) dp[i][0]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=x;j++){
            long long p=0;
            if(j-coins[i]>=0){
                p=(p+dp[i][j-coins[i]])%mod;
            }
            dp[i][j]=(p+dp[i+1][j])%mod;
        }
    }
    cout<<dp[0][x]<<endl;
    return 0;
}
