//https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        int l=1,h=min(x,46340),ans=0;
        while(l<=h){
            int m=(l+h)/2;
            if(m*m<=x){
                ans=m;
                l=m+1;
            }
            else h=m-1;
        }
        return ans;
    }
};
