//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

class Solution {
public: 
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==p || root==q || !root) return root;
        TreeNode* a=solve(root->left,p,q);
        TreeNode* b=solve(root->right,p,q);
        if(a && b) return root;
        else if(a) return a;
        else       return b;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};
