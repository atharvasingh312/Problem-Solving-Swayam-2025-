//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;
        while(l<=h)
        {
            int m=(l+h)/2;
            if(nums[m]==target) return 1;
            else if(nums[l]==nums[h]){
                if(nums[l]==target) return 1;
                h--;
                l++;
            }
            else if(nums[l]<=nums[m])//left
            {
                if(target>=nums[l] && nums[m]>target) h=m-1;
                else l=m+1;
            }
            else{//right
                if(target<nums[l] && nums[m]<target) l=m+1;
                else h=m-1;
            }
            //cout<<l<<" "<<h<<endl;
        }
        return 0; 
    }
};
