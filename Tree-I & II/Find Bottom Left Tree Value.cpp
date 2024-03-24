//https://leetcode.com/problems/find-bottom-left-tree-value/

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int l=-1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            for(int k=0;k<sz;k++)
            {
                TreeNode* f=q.front();
                q.pop();
                if(k==0) l=f->val;
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
        }
        return l;
    }
};
