//https://leetcode.com/problems/jump-game-ii/


class Solution {
public:
    int solve(int i,vector<int> &nums,vector<int> &dp){
        if(i==nums.size()-1) return 0;
        else if(dp[i]!=-1) return dp[i];
        int mn=1001;
        for(int j=1;j<=nums[i] && i+j<nums.size();j++){
            mn=min(mn,1+solve(i+j,nums,dp));
        }
        return dp[i]=mn;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),10001);
        //int ans=solve(0,nums,dp);
        dp[nums.size()-1]=0;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=1;j<=nums[i] && i+j<nums.size();j++){
                dp[i]=min(dp[i],1+dp[i+j]);
            }
        }
        return dp[0];
    }
};
