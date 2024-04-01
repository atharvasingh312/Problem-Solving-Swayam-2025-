//https://leetcode.com/problems/validate-binary-search-tree/description/



class Solution {
public:
    //left limit and right limt
    bool validate(TreeNode* root,long long ll,long long rl)
    {
        if(!root) return true;
        else if(root->val<=ll || root->val>=rl) return false;
        return (validate(root->left,ll,root->val)&validate(root->right,root->val,rl));
    }
    bool isValidBST(TreeNode* root) {
        return validate(root,-(1e11+7),(1e11+7));
    }
};
