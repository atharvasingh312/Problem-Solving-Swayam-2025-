//https://leetcode.com/problems/longest-common-subsequence/description/

class Solution {
public:
    /*recursion:
    int solve(string t1,string t2,int i,int j,vector<vector<int>> &dp){
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        else{
            if(t1[i]==t2[j]) return dp[i][j]=1+solve(t1,t2,i-1,j-1,dp);
            else return dp[i][j]=max(solve(t1,t2,i-1,j,dp),solve(t1,t2,i,j-1,dp));
        }
    }
    */
    //memoization
    /*
    int solve(string &t1,string &t2,int i,int j,vector<vector<int>> &dp){
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        else{
            if(t1[i]==t2[j]) return dp[i][j]=1+solve(t1,t2,i-1,j-1,dp);
            else return dp[i][j]=max(solve(t1,t2,i-1,j,dp),solve(t1,t2,i,j-1,dp));
        }
    }
    */
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<int> prev(m+1,0),cur(m+1,0);
        //return solve(text1,text2,n-1,m-1,dp);
        
        //tabulation:
        /*
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0||j==0) dp[i][j]=0;
                else
                {
                    if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                    else  dp[i][j]=max(dp[i-1][j],dp[i][j-1]); 
                }
            }
        }
        */

        //space optimized

        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0||j==0) cur[j]=0;
                else
                {
                    if(text1[i-1]==text2[j-1]) cur[j]=1+prev[j-1];
                    else  cur[j]=max(prev[j],cur[j-1]); 
                }
            }
            prev=cur;
        }
        return cur[m];
    }
};
