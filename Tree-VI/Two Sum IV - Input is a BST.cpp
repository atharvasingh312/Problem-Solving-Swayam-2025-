//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

class Solution {
public:
    unordered_set<int> st;
    bool findTarget(TreeNode* root, int k) {
        if(!root) return 0;
        else if(st.find(k-(root->val))!=st.end()) return 1;
        st.insert(root->val);
        return findTarget(root->left,k)||findTarget(root->right,k);
    }
};
