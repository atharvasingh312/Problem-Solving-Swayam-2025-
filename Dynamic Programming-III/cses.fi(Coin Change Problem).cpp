//https://cses.fi/problemset/task/1634


#include<bits/stdc++.h>
using namespace std;
 
//recursion and memoization:
/*long long solve(int i,int x,vector<int> &coins,vector<vector<int>> &dp){
    if(i==(int)coins.size()){
        if(x==0) return 0;
        else return INT_MAX;
    }
    else if(dp[i][x]!=-1) return dp[i][x];
    long long p=INT_MAX;
    if(x-coins[i]>=0){
        int t=solve(i,x-coins[i],coins,dp);
        if(t!=INT_MAX) p=1+t;
    }
    return dp[i][x]=min(p,solve(i+1,x,coins,dp));
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
    //int ans=solve(0,x,coins,dp);
    for(int i=1;i<=x;i++) dp[n][i]=INT_MAX;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=x;j++){
            long long p=INT_MAX;
            if(j-coins[i]>=0){
                if(dp[i][j-coins[i]]!=INT_MAX) p=1+dp[i][j-coins[i]];
            }
            dp[i][j]=min(p,(long long)dp[i+1][j]);
        }
    }
    if(dp[0][x]!=INT_MAX) cout<<dp[0][x]<<endl;
    else             cout<<-1<<endl;
    return 0;
}
