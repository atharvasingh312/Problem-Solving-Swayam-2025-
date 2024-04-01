//https://www.geeksforgeeks.org/problems/largest-bst/1

class nodeinfo
{
    public:
    int mx=INT_MIN;
    int mn=INT_MAX;
    bool isbst=1;
    int sz=0;
};
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    nodeinfo* solve(Node* root,int &ans)
    {
        //NUll is valid
        if(!root) return new nodeinfo();
        nodeinfo* l=solve(root->left,ans);
        nodeinfo* r=solve(root->right,ans);
        nodeinfo* node=new nodeinfo();
        node->mx=max(root->data,r->mx);
        node->mn=min(root->data,l->mn);
        node->isbst=0;
        if(l->isbst && r->isbst && l->mx<root->data && r->mn>root->data)
        {
            node->isbst=1; 
            node->sz=l->sz+r->sz+1;
            ans=max(ans,node->sz);
        }
        return node;
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	//we need one flag for binary tree validity & one size parameter
    	int ans=1;
    	int mx=INT_MIN,mn=INT_MAX;
    	solve(root,ans);
    	return ans;
    }
};
