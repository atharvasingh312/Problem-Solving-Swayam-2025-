//https://leetcode.com/problems/shortest-common-supersequence/


class Solution {
public:
    int solve(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        if(i==s1.size() && j==s2.size()) return 0;
        else if(i==s1.size()) return dp[i][j]=1+solve(i,j+1,s1,s2,dp);
        else if(j==s2.size()) return dp[i][j]=1+solve(i+1,j,s1,s2,dp);
        else if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=1+solve(i+1,j+1,s1,s2,dp);
        return dp[i][j]=1+min(solve(i+1,j,s1,s2,dp),solve(i,j+1,s1,s2,dp));
    }
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp(str1.size()+1,vector<int>(str2.size()+1,-1));
        solve(0,0,str1,str2,dp);
        int i=0,j=0;
        string ans;
        while(i<str1.size() && j<str2.size())
        {
            if(str1[i]==str2[j])
            {
                ans.push_back(str1[i]);
                i++;
                j++;
            }
            else{
                if(dp[i+1][j]<dp[i][j+1]){ 
                    ans.push_back(str1[i]);
                    i++;
                }
                else{
                    ans.push_back(str2[j]);
                    j++;
                }
            }
        }
        while(i<str1.size()){
            ans.push_back(str1[i]);
            i++;
        }
        while(j<str2.size()){
            ans.push_back(str2[j]);
            j++;
        }
        return ans;
    }
};
