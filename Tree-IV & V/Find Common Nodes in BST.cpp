//https://www.geeksforgeeks.org/problems/print-common-nodes-in-bst/1

class Solution
{
    public:
    //Function to find the nodes that are common in both BST.
    void inorder(Node* root1,unordered_set<int> &s)
    {
        if(!root1) return;
        inorder(root1->left,s);
        s.insert(root1->data);
        inorder(root1->right,s);
    }
    void solve(Node* root1,unordered_set<int> &s,vector<int> &ans)
    {
        if(!root1) return;
        solve(root1->left,s,ans);
        if(s.find(root1->data)!=s.end()) ans.push_back(root1->data);
        solve(root1->right,s,ans);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
        unordered_set<int> s;
        inorder(root1,s);
        vector<int> ans;
        solve(root2,s,ans);
        return ans;
    }
};
