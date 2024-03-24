//https://www.codingninjas.com/studio/problems/tree-height_4609628?leftPanelTabValue=SUBMISSION

int heightOfBinaryTree(TreeNode<int> *root)
{
	// Write your code here.
    if(!root) return 0;
    return 1+max(heightOfBinaryTree(root->left),heightOfBinaryTree(root->right));
}
