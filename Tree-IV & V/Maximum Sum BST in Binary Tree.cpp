//https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

class nodeinfo{
    public:
    int val=0;
    int mx=INT_MIN;
    int mn=INT_MAX;
    bool isbst=1;
};
class Solution {
public:
    nodeinfo* solve(TreeNode* root,int &ans)
    {
        if(!root)
        return new nodeinfo();
        nodeinfo* l=solve(root->left,ans);
        nodeinfo* r=solve(root->right,ans);
        nodeinfo* node=new nodeinfo();
        node->isbst=0;
        node->mx=max(root->val,r->mx);
        node->mn=min(root->val,l->mn);
        if(l->isbst && r->isbst && root->val<r->mn && root->val>l->mx)
        {
            node->isbst=1;
            node->val=r->val+l->val+root->val;
            ans=max(ans,node->val);
        }
        cout<<node->val<<" "<<node->mx<<" "<<node->mn<<endl;
        return node;
    }
    int maxSumBST(TreeNode* root)
    {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};
