//https://www.naukri.com/code360/problems/boundary-traversal-of-binary-tree_790725?leftPanelTabValue=PROBLEM


void left(TreeNode<int> *root, vector<int> &ans) 
{
    if(!root || (!root->left && !root->right)) return;
    ans.push_back(root->data);
    if(root->left) left(root->left,ans);
    else              left(root->right,ans);
}
void inorder(TreeNode<int> *root,vector<int> &ans) {
    if(!root) return;
    inorder(root->left,ans);
    if (!root->left && !root->right) {
        ans.push_back(root->data);
    }
    inorder(root->right,ans);
}
void right(TreeNode<int> *root,vector<int> &ans){
    if(!root || (!root->left && !root->right)) return;
    if(root->right) right(root->right,ans);
    else              right(root->left,ans);
    ans.push_back(root->data);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;
    ans.push_back(root->data);
    //need to deal differently for left and right subtree
    left(root->left,ans);
    inorder(root,ans);//for nochild
    right(root->right,ans);
    return ans;
}
