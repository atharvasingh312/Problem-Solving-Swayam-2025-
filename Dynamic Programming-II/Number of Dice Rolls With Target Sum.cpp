//https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/


class Solution {
public:
    long long solve(int n,int k,int target,vector<vector<long long>> &dp){
        long long mod=(int)(1e9+7);
        if(n==0 && target==0) return 1;
        else if(!n) return 0;
        else if(dp[target][n]!=-1) return dp[target][n];
        long long c=0;
        for(int j=1;j<=k && target-j>=0;j++)
        c=(c+solve(n-1,k,target-j,dp)%mod)%mod;
        return dp[target][n]=c;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(target+1,vector<long long>(n+1,0));
        long long mod=1e9+7;
        dp[0][0]=1;
        for(int i=0;i<=target;i++){
            for(int j=1;j<=n;j++){
                for(int l=1;l<=k && i-l>=0;l++)
                dp[i][j]=(dp[i][j]+dp[i-l][j-1])%mod;
            }
        }
        return dp[target][n];
    }
};
