//https://leetcode.com/problems/range-sum-of-bst/description/


class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int c=0;
        if(root->val>=low && root->val<=high)  c=root->val;
        return c+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
    }
};
