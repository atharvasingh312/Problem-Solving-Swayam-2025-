//https://leetcode.com/problems/house-robber-ii/


class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int prev2=0,prev=0;
        int a=0,b=0;
        for(int i=n-2;i>=0;i--)
        {
            a=max(nums[i]+prev2,prev);
            prev2=prev;
            prev=a;
        }
        prev2=0,prev=0;
        for(int i=n-1;i>0;i--)
        {
            b=max(nums[i]+prev2,prev);
            prev2=prev;
            prev=b;
        }
        return max(a,b);
    }
};
