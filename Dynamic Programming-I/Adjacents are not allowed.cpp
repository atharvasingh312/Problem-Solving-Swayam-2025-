//https://www.geeksforgeeks.org/problems/adjacents-are-not-allowed3528/1


class Solution{
public:
    int solve(int i,vector<vector<int>> &mat,vector<int> &dp){
        if(i>=mat[0].size()) return 0;
        else if(dp[i]!=-1) return dp[i];
        return dp[i]=max(max(mat[0][i],mat[1][i])+solve(i+2,mat,dp),solve(i+1,mat,dp));
    }
    int maxSum(int N, vector<vector<int>> mat)
    {
        // code here
        vector<int> dp(N+2,0);
        for(int i=N-1;i>=0;i--)
        {
            dp[i]=max(max(mat[0][i],mat[1][i])+dp[i+2],dp[i+1]);
        }
        return dp[0];
    }
};
