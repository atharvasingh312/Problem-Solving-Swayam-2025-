//https://leetcode.com/problems/binary-tree-paths/


class Solution {
public:
    void solve(TreeNode* root,vector<string> &ans,string &temp)
    {
        if(!root) return;
        else if(!root->left && !root->right)
        {
            string nt=temp;
            temp+=to_string(root->val);
            ans.push_back(temp);
            temp=nt;
            return;
        }
        string nt=temp;
        temp+=to_string(root->val)+"->";
        solve(root->left,ans,temp);
        solve(root->right,ans,temp);
        temp=nt;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp="";
        solve(root,ans,temp);
        return ans;
    }
};
