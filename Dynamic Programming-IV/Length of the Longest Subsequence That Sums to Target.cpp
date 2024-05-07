//https://leetcode.com/problems/length-of-the-longest-subsequence-that-sums-to-target/


class Solution {
public:
    /*int solve(int i,vector<int> &nums,int t){
        if(i==nums.size()){
            if(t==0) return 0;
            return INT_MIN;
        }
        int p=INT_MIN;
        if(t>=nums[i]) p=1+solve(i+1,nums,t-nums[i]);
        return  max(p,solve(i+1,nums,t));
    }*/
    //memoization
    int solve(int i,vector<int> &nums,int t,vector<vector<int>> &dp){
        if(i==nums.size()){
            if(t==0) return 0;
            return INT_MIN;
        }
        else if(dp[i][t]!=-1) return dp[i][t];
        int p=INT_MIN;
        if(t>=nums[i]) p=1+solve(i+1,nums,t-nums[i],dp);
        return  dp[i][t]=max(p,solve(i+1,nums,t,dp));
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(target+1,0));
        for(int i=1;i<=target;i++) dp[nums.size()][i]=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int j=0;j<=target;j++)
            {
                int p=INT_MIN;
                if(j>=nums[i]) p=1+dp[i+1][j-nums[i]];
                dp[i][j]=max(p,dp[i+1][j]);
            }
        }
        if(dp[0][target]<0) return -1;
        return dp[0][target];
    }
};
