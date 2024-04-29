//https://leetcode.com/problems/solving-questions-with-brainpower/description/

class Solution {
public:
    long long solve(int i,vector<vector<int>> &questions,vector<long long> &dp) {
        if(i>=questions.size()) return 0;
        else if(dp[i]!=-1) return dp[i];
        long long p=questions[i][0]+solve(i+questions[i][1]+1,questions,dp);
        long long u=solve(i+1,questions,dp);
        return dp[i]=max(u,p);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        int mx=INT_MIN;
        for(auto x:questions)
        {
            mx=max(mx,x[1]);
        }
        vector<long long> dp(n+mx+1,0);
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=max(questions[i][0]+dp[i+questions[i][1]+1],dp[i+1]);
        }
        return dp[0];
    }
};
