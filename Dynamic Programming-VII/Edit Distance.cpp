//https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int solve(int i,int j,string &word1,string &word2,vector<vector<int>> &dp)
    {
        if(i==word1.size()) return word2.size()-j;
        else if(j==word2.size()) return word1.size()-i;
        else if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j]=solve(i+1,j+1,word1,word2,dp);
        return dp[i][j]=1+min({solve(i+1,j,word1,word2,dp),solve(i+1,j+1,word1,word2,dp),solve(i,j+1,word1,word2,dp)});
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> curr(word1.size()+1,0),prev(word1.size()+1,0);
        for(int i=0;i<word1.size();i++)
        {
            dp[i][word2.size()]=word1.size()-i;
        }
        for(int i=0;i<word2.size();i++)
        {
            dp[word1.size()][i]=word2.size()-i;
        }
        for(int i=word1.size()-1;i>=0;i--)
        {
            for(int j=word2.size()-1;j>=0;j--)
            {
                if(word1[i]==word2[j]) dp[i][j]=dp[i+1][j+1];
                else dp[i][j]=1+min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]});
            }
        }
        return dp[0][0];
    }
};
