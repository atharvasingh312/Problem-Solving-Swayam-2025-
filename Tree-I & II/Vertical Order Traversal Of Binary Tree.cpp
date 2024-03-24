//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

class Solution {
public:
    void solve(TreeNode* root,int x,int y,map<int,map<int,multiset<int>>> &mp)
    {
        if(!root) return;
        mp[x][y].insert(root->val);
        solve(root->left,x-1,y+1,mp);
        solve(root->right,x+1,y+1,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        solve(root,0,0,mp);
        vector<vector<int>> v;
        for(auto x:mp)
        {
            vector<int> temp;
            for(auto y:x.second)
            {
                for(auto z:y.second)
                temp.push_back(z);
            }
            v.push_back(temp);
        }
        return v;
    }
};
