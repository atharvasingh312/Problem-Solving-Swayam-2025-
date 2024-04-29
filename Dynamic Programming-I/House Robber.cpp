//https://leetcode.com/problems/house-robber/

class Solution {
public:
    int solve(vector<int> &nums,int i,vector<int> &dp)
    {
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        else{
            return dp[i]=max(nums[i]+solve(nums,i+2,dp),solve(nums,i+1,dp));
        } 
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=0,prev2=0;
        int ans=0;
        for(int i=nums.size()-1;i>=0;i--){
            ans=max(nums[i]+prev2,prev);
            prev2=prev;
            prev=ans;
        }
        return ans;
    }
};
