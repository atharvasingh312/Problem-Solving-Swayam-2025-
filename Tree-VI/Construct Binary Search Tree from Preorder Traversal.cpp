//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/


class Solution {
public:
    TreeNode* solve(vector<int> &pre,int ps,int pe)
    {
        if(ps>pe) return NULL;
        TreeNode* root=new TreeNode(pre[ps]);
        int i=ps+1;
        while(i<=pe && pre[i]<pre[ps]) i++;
        root->left=solve(pre,ps+1,i-1);
        root->right=solve(pre,i,pe);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder,0,preorder.size()-1);
    }
};
