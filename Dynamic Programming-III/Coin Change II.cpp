//https://leetcode.com/problems/coin-change-ii/

class Solution {
public:
    int solve(int a,vector<int>& c,int i,vector<vector<int>>& dp)
    {
        int p=0;
        if(i==c.size())
        {
            if(a==0) return 1;
            return 0;
        }
        if(dp[i][a]!=-1) return dp[i][a];
        else if(c[i]<=a) p=solve(a-c[i],c,i,dp);
        return dp[i][a]=p+solve(a,c,i+1,dp);   
    } 
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<int> curr(amount+1,0),nex(amount+1,0);
        nex[0]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=amount;j++){
                int t=0,nt=0;
                if(j>=coins[i]) t=curr[j-coins[i]];
                nt=nex[j];
                curr[j]=t+nt;
            }
            nex=curr;
        }
        return nex[amount];
    }
};
