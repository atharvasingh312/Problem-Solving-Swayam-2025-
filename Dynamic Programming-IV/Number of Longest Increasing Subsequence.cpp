//https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution {
public:
    int findNumberOfLIS(std::vector<int>& nums) {
        vector<int> dp(nums.size(),1),count(nums.size(),1);
        int mx=1;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j]){
                    if(dp[i]<dp[j]+1) count[i]=count[j];
                    else if(dp[i]==dp[j]+1) count[i]+=count[j];
                    dp[i]=max(dp[i],dp[j]+1);
                    mx=max(dp[i],mx);
                }
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(dp[i]==mx){
                ans+=count[i];
            }
        }
        return ans;
    }
};
