//https://leetcode.com/problems/same-tree/


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        else if((!p && q) || (p && !q)) return false;
        else if(p->val!=q->val) return false;
        bool b=1;
        if(p->left || q->left){
            b=(b&isSameTree(p->left,q->left));
        }
        if(p->right || q->right){
            b=(b&isSameTree(p->right,q->right));
        }
        return b; 
    }
};
