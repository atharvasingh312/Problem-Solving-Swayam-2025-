//https://leetcode.com/problems/binary-tree-level-order-traversal/description/


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==nullptr) return {}; 
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int> l;
            for(int i=0;i<s;i++){
                TreeNode* x=q.front();
                if(x==nullptr){
                    q.pop();
                    continue;
                }
                l.push_back(x->val);
                if(x->left!=nullptr) q.push(x->left);
                if(x->right!=nullptr) q.push(x->right);
                q.pop();
            }
            ans.push_back(l);
        }
        return ans; 
    }
};
