//https://www.interviewbit.com/problems/path-to-given-node/


bool sol(TreeNode* A, int B,vector<int> &path)
{
    if(!A) return false;
    path.push_back(A->val);
    if(A->val==B) return true;
    if(sol(A->left,B,path)) return true;
    if(sol(A->right,B,path)) return true;
    path.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> path;
    sol(A,B,path);
    return path;
}
