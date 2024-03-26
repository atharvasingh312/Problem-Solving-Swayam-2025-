//https://leetcode.com/problems/binary-tree-right-side-view/


class Solution {
public:
    void solve(vector<int> &ans,TreeNode* root,int l)
    {
        if(!root) return;
        if(ans.size()<l) ans.push_back(root->val);
        solve(ans,root->right,l+1);
        solve(ans,root->left,l+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(ans,root,1);
        return ans;
    }
};
