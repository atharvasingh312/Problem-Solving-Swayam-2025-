//https://leetcode.com/problems/recover-binary-search-tree/


class Solution {
public:
    TreeNode* a=NULL,*b=NULL;
    int f=0;
    //previous passed by address
    void find(TreeNode* &prev,TreeNode *root)
    {
        if(!root) return;
        find(prev,root->left);
        if(prev && prev->val>root->val)
        {
            if(!f){
                cout<<"hello";
                a=prev;
                b=root;
                f=1;
            }
            else b=root;
        }
        prev=root;
        find(prev,root->right);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* prev=NULL;
        find(prev,root);
        int temp=a->val;
        a->val=b->val;
        b->val=temp;
    }
};
