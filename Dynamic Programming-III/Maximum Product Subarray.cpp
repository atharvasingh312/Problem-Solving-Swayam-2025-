//https://leetcode.com/problems/maximum-product-subarray/description/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mxprod=1,mnprod=1,ans=nums[0];
        for(int i=0;i<nums.size();i++){
            int tmx=mxprod,tmn=mnprod;
            if(nums[i]>=0){
                mxprod=max(nums[i],tmx*nums[i]);
                mnprod=min(nums[i],tmn*nums[i]);
            }
            else{
                mxprod=max(tmn*nums[i],nums[i]);
                mnprod=min(tmx*nums[i],nums[i]);
            }
            ans=max(mxprod,ans);
        }
        return ans;
    }
};
