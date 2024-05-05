//https://leetcode.com/problems/longest-increasing-subsequence/description/


class Solution {
public:
    //recursion:
    /*int solve(int prev,int i,vector<int> &nums) {
        if(i==nums.size()) return 0;
        int p=0;
        if(prev==-1 || (nums[i]>nums[prev]))
        p=1+solve(i,i+1,nums);
        return max(p,solve(prev,i+1,nums));
    }*/
    //memoization
    /*
    int solve(int prev,int i,vector<int> &nums,vector<vector<int>> &dp) {
        if(i==nums.size()) return 0;
        else if(dp[prev+1][i]!=-1) return dp[prev+1][i];
        int p=0;
        if(prev==-1 || (nums[i]>nums[prev]))
        p=1+solve(i,i+1,nums,dp);
        return dp[prev+1][i]=max(p,solve(prev,i+1,nums,dp));
    }*/
    int lengthOfLIS(vector<int>& nums) {
        //tabuation
        /*vector<int> dp(nums.size(),1);
        int mx=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j])
                dp[i]=max(dp[i],dp[j]+1);
            }
            mx=max(mx,dp[i]);
        }
        return mx;*/
        //binary search
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>dp.back()) dp.push_back(nums[i]);
            else{
                int j=lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
                dp[j]=nums[i];
            }
        }
        return dp.size();
    }
};
