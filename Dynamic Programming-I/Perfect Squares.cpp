//https://leetcode.com/problems/perfect-squares/description/

class Solution {
public:
    int solve(int n,vector<int> &dp)
    {
        int c=INT_MAX;
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i*i<=n;i++){
            c=min(1+solve(n-(i*i),dp),c);
        }
        return dp[n]=c;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int j=0;j<=n;j++){
            for(int i=1;i*i<=j;i++){
                dp[j]=min(1+dp[j-(i*i)],dp[j]);
            }
        }
        return dp[n];
    }
};
