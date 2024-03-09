https://leetcode.com/problems/find-minimum-in-rotated-sorted-array


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        int b=0,e=nums.size()-1;
        int m=0;
        vector<int> v;
        int l=nums.size()-1,r=0;
        while(b<=e)
        {
            m=(b+e)/2;
            if(nums[m]<target) b=m+1;
            else if(nums[m]>=target)
            {
                if(nums[m]==target) l=m;
                e=m-1;
            }
        }
        if(nums[l]==target) v.push_back(l);
        else                v.push_back(-1);
        b=0,e=nums.size()-1;
        while(b<=e)
        {
            m=(b+e)/2;
            if(nums[m]<=target)
            {
                if(nums[m]==target) r=m;
                b=m+1;
            }
            else      e=m-1;
        }
        if(nums[r]==target) v.push_back(r);
        else                v.push_back(-1);
        return v;
    }
};
