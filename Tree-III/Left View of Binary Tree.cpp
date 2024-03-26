//https://www.codingninjas.com/studio/problems/left-view-of-binary-tree_625707?leftPanelTabValue=SUBMISSION


void solve(vector<int> &ans, BinaryTreeNode<int> *root, int l) {
    if(!root) return;
    if (ans.size() < l) {
        ans.push_back(root->data);
    }
    solve(ans,root->left,l+1);
    solve(ans,root->right,l+1);
}
vector<int> printLeftView(BinaryTreeNode<int>* root) {
    // Write your code here.
    vector<int> ans;
    solve(ans,root,1);
    return ans;
}
