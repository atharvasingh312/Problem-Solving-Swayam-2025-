//https://leetcode.com/problems/path-sum/description/

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        else if(!root->left && !root->right && targetSum-root->val==0) return 1;
        else{
            return hasPathSum(root->left,targetSum-root->val) | hasPathSum(root->right,targetSum-root->val);
        }
    }
};
