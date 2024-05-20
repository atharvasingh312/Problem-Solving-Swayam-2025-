//https://leetcode.com/discuss/interview-question/538568/google-onsite-min-operations-to-reduce-number-to-1

#include <bits/stdc++.h>
using namespace std;

int solve(int n,vector<int> &dp){
    if(n==1) return 0;
    else if(dp[n]!=-1) return dp[n];
    int p1=INT_MAX,p2=INT_MAX;
    if(n%2==0){
        p1=solve(n/2,dp);
    }
    if(n%3==0){
        p2=solve(n/3,dp);
    }
    return dp[n]=1+min({p1,p2,solve(n-1,dp)});
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> dp(n+1,INT_MAX);
        dp[1]=0;
        for(int i=2;i<=n;i++)
        {
            int p1=INT_MAX,p2=INT_MAX;
            if(i%2==0){
                p1=dp[i/2];
            }
            if(i%3==0){
                p2=dp[i/3];
            }
            dp[i]=1+min({p1,p2,dp[i-1]});
        }
        //cout<<solve(n,dp)<<endl;
        cout<<dp[n]<<endl;
    }
    return 0;
}
