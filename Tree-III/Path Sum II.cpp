//https://leetcode.com/problems/path-sum-ii/description/


class Solution {
public:
    vector<vector<int>> ans;
    void solve(TreeNode* root, int s,vector<int> x)
    {
        if(root==NULL) return;
        else if(!root->left && !root->right)
        {
            if(s-root->val==0){
                x.push_back(root->val);
                ans.push_back(x);
            }
        }
        else
        {
            x.push_back(root->val);
            solve(root->left,s-root->val,x);
            solve(root->right,s-root->val,x);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> x;
        solve(root,targetSum,x);
        return ans;
    }
};
