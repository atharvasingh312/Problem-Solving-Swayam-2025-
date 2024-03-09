//https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        else if(nums[0]!=nums[1]) return nums[0];
        else if(nums[nums.size()-1]!=nums[nums.size()-2]) return nums[nums.size()-1];
        int l=2,r=nums.size()-3,m=0;
        while(l<=r){
            int m=(l+r)/2;
            int ch=m;
            if(nums[m-1]==nums[m]) ch--;
            if(ch%2==0) l=m+1;
            else        r=m-1;
        }
        return nums[r];
    }
};
