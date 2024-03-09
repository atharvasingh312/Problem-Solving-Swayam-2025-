https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/


class Solution {
public:
    int findMin(vector<int>& nums) {
        //the min element will be the point of rotation
        int l=0,h=nums.size()-1,m;
        //if array is already sorted:
        if(nums[0]<=nums[h]) return nums[0];
        //if not present on right side
        int ans=INT_MAX;
        while(l<=h)
        {
            m=(l+h)/2;
            ans=min(ans,nums[m]);
            if(nums[h]<nums[m]) l=m+1;
            else                h=m-1;
        }
        return ans;
    }
};
