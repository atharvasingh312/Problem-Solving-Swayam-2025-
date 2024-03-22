//https://leetcode.com/problems/median-of-two-sorted-arrays/


class Solution {
public:
    double binsolve(vector<int>& nums1, vector<int>& nums2)
    {
        int n=nums1.size();
        int m=nums2.size();
        int sz=(m+n+1)/2;
        int b=0,e=n;
        while(b<=e)
        {
            int mid=(b+e)/2;
            int mid2=sz-mid;
            int l1=(mid-1>=0)?nums1[mid-1]:INT_MIN;
            int r1=(mid!=n)?nums1[mid]:INT_MAX;
            int l2=(mid2-1>=0)?nums2[mid2-1]:INT_MIN;
            int r2=(mid2!=m)?nums2[mid2]:INT_MAX;
            if(l1<=r2 && l2<=r1){
                if((m+n)%2==0){
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                else return max(l1,l2);
            }
            else if(l1>r2)     e=mid-1;
            else               b=mid+1;
        }
        return -1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //in thid we assume that we have (m+n+1)/2 element on bigger side
        if(nums1.size()<=nums2.size()) return binsolve(nums1,nums2);
        return binsolve(nums2,nums1);
    }
};
