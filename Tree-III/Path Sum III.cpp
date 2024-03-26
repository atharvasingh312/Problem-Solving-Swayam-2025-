//https://leetcode.com/problems/path-sum-iii/

class Solution {
public:
    int solve(TreeNode* root, int t,unordered_map<int,int> &mp,int sum)
    {
        if(!root) return 0;
        int c=0;
        sum=(sum+root->val)%(1000000007);
        if(mp.find(sum-t)!=mp.end()) c+=mp[sum-t];
        mp[sum]++;
        c=(c+solve(root->left,t,mp,sum))%(1000000007);
        c=(c+solve(root->right,t,mp,sum))%(1000000007);
        mp[sum]--;
        if(mp[sum]==0) mp.erase(sum);
        return c;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int,int> sum;
        sum[0]=1;
        return solve(root,targetSum,sum,0);
    }
};
