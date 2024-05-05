//https://leetcode.com/problems/dungeon-game/description/


class Solution {
public:
    //recursion:
    /*int solve(int i,int j,vector<vector<int>>& dungeon){
        int n=dungeon.size(),m=dungeon[0].size();
        if(i==n-1 && j==m-1) return max(1,1-dungeon[i][j]);
        else if(i>=n || j>=m) return 10000;
        return max(1,min(solve(i+1,j,dungeon),solve(i,j+1,dungeon))-dungeon[i][j]);  
    }*/

    //memoization:
    /*int solve(int i,int j,vector<vector<int>>& dungeon,vector<vector<int>> &dp){
        int n=dungeon.size(),m=dungeon[0].size();
        if(i==n-1 && j==m-1) return max(1,1-dungeon[i][j]);
        else if(i>=n || j>=m) return 10000;
        else if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=max(1,min(solve(i+1,j,dungeon,dp),solve(i,j+1,dungeon,dp))-dungeon[i][j]);  
    }*/

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size(),m=dungeon[0].size();
        vector<int> nex(m,0),cur(m,0);
        //return solve(0,0,dungeon,dp);
        nex[m-1]=max(1,1-dungeon[n-1][m-1]);
        cur[m-1]=max(1,1-dungeon[n-1][m-1]);
        /*for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1) continue;
                int p=10000;
                if(i+1<n) p=min(p,dp[i+1][j]);
                if(j+1<m) p=min(p,dp[i][j+1]);
                dp[i][j]=max(1,p-dungeon[i][j]);
            }
        }
        return dp[0][0];*/
        //space optimized
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1) continue;
                int p=10000;
                if(i+1<n) p=min(p,nex[j]);
                if(j+1<m) p=min(p,cur[j+1]);
                cur[j]=max(1,p-dungeon[i][j]);
            }
            nex=cur;
        }
        return cur[0];
    }
};
