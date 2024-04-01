//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

class Solution {
public:
    TreeNode* solve(int l,int h,vector<int>& nums)
    {
        if(l>h) return NULL;
        int m=(l+h)/2;
        TreeNode* n=new TreeNode(nums[m]);
        n->left=solve(l,m-1,nums);
        n->right=solve(m+1,h,nums);
        return n; 
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(0,nums.size()-1,nums);
    }
};
