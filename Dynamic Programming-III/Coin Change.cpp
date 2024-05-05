//https://leetcode.com/problems/coin-change/description/


class Solution {
public:
    //recursion:
    /*int solve(int i,vector<int> &coins,int t)
    {
        if(i==coins.size()){
            if(t==0) return 0;
            else     return 1001;
        }
        int p=1001;
        if(coins[i]<=t){
            p=1+solve(i,coins,t-coins[i]);
        }
        return min(p,solve(i+1,coins,t));
    }*/
    //memoization
    /*int solve(int i,vector<int> &coins,int t,vector<vector<int>> &dp)
    {
        if(i==coins.size()){
            if(t==0) return 0;
            else     return 10001;
        }
        else if(dp[i][t]!=-1) return dp[i][t];
        int p=10001;
        if(coins[i]<=t){
            p=1+solve(i,coins,t-coins[i],dp);
        }
        return dp[i][t]=min(p,solve(i+1,coins,t,dp));
    }*/
    int coinChange(vector<int>& coins, int amount) {
       //tabulation
       /* vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,0));
        for(int i=1;i<=amount;i++) dp[coins.size()][i]=10001;
        for(int i=coins.size()-1;i>=0;i--){
            for(int j=0;j<=amount;j++){
                dp[i][j]=10001;
                if(coins[i]<=j)
                dp[i][j]=min(dp[i][j],1+dp[i][j-coins[i]]);
                dp[i][j]=min(dp[i][j],dp[i+1][j]);
            }
        }
        cout<<dp[0][amount]<<endl;
        if(dp[0][amount]>10000)
        return -1;
        else
        return dp[0][amount];*/
      //space optimation
        vector<int> curr(amount+1,0),nex(amount+1,0);
        for(int i=1;i<=amount;i++){
            nex[i]=10001;
            curr[i]=nex[i];
        }
        for(int i=coins.size()-1;i>=0;i--){
            for(int j=0;j<=amount;j++){
                curr[j]=10001;
                if(coins[i]<=j)
                curr[j]=min(curr[j],1+curr[j-coins[i]]);
                curr[j]=min(curr[j],nex[j]);
            }
            nex=curr;
        }
        if(curr[amount]>10000)
        return -1;
        else
        return curr[amount];
    }
};
