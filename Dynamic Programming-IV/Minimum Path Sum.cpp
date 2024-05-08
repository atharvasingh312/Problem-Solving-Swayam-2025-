//https://leetcode.com/problems/minimum-path-sum/description/


class Solution {
public:
    //memoization:
    int solve(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp)
    {
        int m=grid.size(),n=grid[0].size();
        if(i>=m || j>=n) return 1000;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==m-1 && j==n-1) return grid[i][j];
        return dp[i][j]=grid[i][j]+min(solve(grid,i+1,j,dp),solve(grid,i,j+1,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size()+1,vector<int>(grid[0].size()+1,100001));
        //tabulation:
        dp[grid.size()-1][grid[0].size()-1]=grid[grid.size()-1][grid[0].size()-1];
        for(int i=grid.size()-1;i>=0;i--)
        {
            for(int j=grid[0].size()-1;j>=0;j--)
            {
                if(i==grid.size()-1 && j==grid[0].size()-1) continue;
                dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};
