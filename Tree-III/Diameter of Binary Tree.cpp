//https://leetcode.com/problems/diameter-of-binary-tree/


class Solution {
public:
    int solve(TreeNode* root,int &ans){
        if(!root) return 0;
        int l=0,r=0;
        if(root->left){
            l=1+solve(root->left,ans);
        }
        if(root->right){
            r=1+solve(root->right,ans);
        }
        ans=max(ans,l+r);
        return max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        int x=solve(root,ans);
        return ans;
    }
};
