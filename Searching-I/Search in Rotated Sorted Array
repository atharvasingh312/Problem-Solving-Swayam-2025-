https://leetcode.com/problems/search-in-rotated-sorted-array/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;
        while(l<=h)
        {
            int m=(l+h)/2;
            if(nums[m]==target) return m;
            else if(nums[0]<=nums[m])//left
            {
                if(target>=nums[0] && nums[m]>target) h=m-1;
                else l=m+1;
            }
            else{//right
                if(target<nums[0] && nums[m]<target) l=m+1;
                else h=m-1;
            }
            cout<<l<<" "<<h<<endl;
        }
        return -1; 
    }
};
