//https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/1222305037/

class Solution {
public:
    int res=-1;
    void solve(TreeNode* root, int &k)
    {
        if(!root) return;
        kthSmallest(root->left,k);
        k--;
        if(k==0 && res==-1) res=root->val;
        kthSmallest(root->right,k);
    }
    int kthSmallest(TreeNode* root, int &k) {
        solve(root,k);
        return res;
    }
};
