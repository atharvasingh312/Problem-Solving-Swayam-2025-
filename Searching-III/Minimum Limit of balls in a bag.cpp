// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/



class Solution {
public:
    bool check(int mxball,vector<int>& nums, int maxops)
    {
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>mxball){
                c+=(nums[i]/mxball)-1;
                if(nums[i]%mxball!=0) c++;
            }
        }
        return c<=maxops;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        //need to minimize max number of ball
        //max operation se kam me ye kar pau
        int l=1,h=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            h=max(h,nums[i]);
        }
        int ans=0;
        while(l<=h){
            int m=(l+h)/2;//max balls in a bag
            cout<<l<<" "<<h<<endl;
            if(check(m,nums,maxOperations))
            {
                h=m-1;
                ans=m;
            }
            else l=m+1;
        }
        return ans;
    }
};
