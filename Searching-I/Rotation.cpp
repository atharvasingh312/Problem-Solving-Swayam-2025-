https://www.geeksforgeeks.org/problems/rotation4723/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article


class Solution{
public:	
	int findKRotation(int nums[], int n) {
	    // code here
	    int b=0,e=n-1;
	    if(nums[b]<nums[e]) return 0;//not rotated
	    while(b<e)
	    {
	        int m=(b+e)/2;
	        if(nums[m]>nums[e]) b=m+1;
	        else                e=m;
	    }
	    return e;
	}

};
