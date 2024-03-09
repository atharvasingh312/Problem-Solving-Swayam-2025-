https://leetcode.com/problems/find-peak-element/


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        if(nums.size()==1 || nums[0]>nums[1]) return 0;
        else if(nums[h]>nums[h-1]) return h;
        l=1,h--;
        while(l<=h)
        {
            int m=(l+h)/2;
            if(nums[m]>nums[m-1] && nums[m]>nums[m+1]) return m;
            else if(nums[m-1]<nums[m] && nums[m]<nums[m+1]) l=m+1;
            else h=m-1;
        }
        return nums[h];
    }
};
