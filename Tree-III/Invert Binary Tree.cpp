//https://leetcode.com/problems/invert-binary-tree/


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* temp=root->left;        
        root->left=invertTree(root->right);
        root->right=invertTree(temp);
        return root;
    }
};
