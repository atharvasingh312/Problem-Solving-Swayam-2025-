//https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int l=0,h=n-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(target<=matrix[mid][m-1] && target>=matrix[mid][0])
            {
                int s=0,e=m-1;
                while(s<=e)
                {
                    int md=(s+e)/2;
                    if(target==matrix[mid][md])    return 1;
                    else if(target<matrix[mid][md])  e=md-1;
                    else                             s=md+1;
                }
                return 0;
            }
            else if(target<=matrix[mid][0]) h=mid-1;
            else                            l=mid+1;
        }
        return 0;
    }
};
