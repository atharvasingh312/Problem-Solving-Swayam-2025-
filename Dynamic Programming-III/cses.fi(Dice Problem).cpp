//https://cses.fi/problemset/task/1633


#include <bits/stdc++.h>
using namespace std;
 
int solve(int i,int n,vector<int> &dp){
    int mod=(int)(1e9+7);
    if(i==n) return 1;
    else if(dp[i]!=-1) return dp[i];
    long long c=0;
    for(int j=i+1;j<=i+6 && j<=n;j++){
        c=(c+solve(j,n,dp))%mod;
    }
    return dp[i]=c;
}
int main()
{
    int mod=(int)(1e9+7);
    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    dp[n]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<=i+6 && j<=n;j++){
            dp[i]=(dp[i]+dp[j])%mod;
        }
    }
    cout<<dp[0]<<endl;
    return 0;
}
