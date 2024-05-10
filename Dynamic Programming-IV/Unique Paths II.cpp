//https://leetcode.com/problems/unique-paths-ii/


class Solution {
public:
    int solve(vector<vector<int>>& g,int i,int j,vector<vector<int>>& dp)
    {
        if(i>=g.size() || j>=g[0].size()) return 0;
        else if(g[i][j]==1) return 0;
        else if(i==g.size()-1 && j==g[0].size()-1) return 1;
        else if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=solve(g,i+1,j,dp)+solve(g,i,j+1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]==1) return 0;
        vector<vector<long>> dp(n+1,vector<long>(m+1,0));
        dp[n-1][m-1]=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(obstacleGrid[i][j]==0)
                {
                    dp[i][j]+=dp[i+1][j]+dp[i][j+1];
                }
            }
        }
        return dp[0][0];
    }
};
