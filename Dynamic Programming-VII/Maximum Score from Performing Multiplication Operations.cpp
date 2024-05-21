//https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/


class Solution {
public:
    int solve(int i,int j,vector<int>& nums, vector<int>& multipliers,vector<vector<int>> &dp)
    {
        int n=nums.size();
        if(j==multipliers.size()) return 0;
        else if(dp[i][j]!=-1) return dp[i][j];
        int k=n-1-(j-i);
        return dp[i][j]=max(multipliers[j]*nums[i]+solve(i+1,j+1,nums,multipliers,dp),multipliers[j]*nums[k]+solve(i,j+1,nums,multipliers,dp));
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) 
    {
        vector<int> curr(multipliers.size()+1,0),prev(multipliers.size()+1,0);
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int j=multipliers.size()-1;j>=0;j--)
            {
                int k=nums.size()-1-(j-i);
                if(k>=0 & k<nums.size())
                prev[j]=max(multipliers[j]*nums[i]+curr[j+1],multipliers[j]*nums[k]+prev[j+1]);
            }
            curr=prev;
        }
        //return solve(0,0,nums,multipliers,dp);
        return curr[0];
    }
};
