//https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx=nums[0],ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            mx=max(mx+nums[i],nums[i]);
            ans=max(ans,mx);
        }
        return ans;
    }
};
