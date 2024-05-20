//https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
    bool solve(int i,int j,string &s,string &p,vector<vector<int>> &dp){
        if(i==s.size() && j==p.size()) return 1;
        else if(i!=s.size() && j==p.size()) return 0;
        else if(i==s.size() && j!=p.size())
        {
            if(p[j]=='*') return solve(i,j+1,s,p,dp);
            else return 0;
        }
        else if(dp[i][j]!=-1) return dp[i][j];
        else if(s[i]==p[j] || p[j]=='?') return dp[i][j]=solve(i+1,j+1,s,p,dp);
        else if(p[j]=='*')
        {
            return dp[i][j]=(solve(i+1,j,s,p,dp)||solve(i+1,j+1,s,p,dp)||solve(i,j+1,s,p,dp));
        }
        return 0;
    }
    bool isMatch(string s, string p) {
        vector<bool> curr(p.size()+1,0),prev(p.size()+1,0);
        /*
        dp[s.size()][p.size()]=1;
        for(int i=p.size()-1;i>=0;i--){
            if(p[i]=='*')
            dp[s.size()][i]=dp[s.size()][i+1];
        }
        for(int i=s.size()-1;i>=0;i--)
        {
            for(int j=p.size()-1;j>=0;j--){
                if(s[i]==p[j] || p[j]=='?')  dp[i][j]=dp[i+1][j+1];
                else if(p[j]=='*')
                {
                    dp[i][j]=(dp[i+1][j]||dp[i+1][j+1]||dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
        */
        curr[p.size()]=1;
        for(int i=p.size()-1;i>=0 && p[i]=='*';i--)
        {
            curr[i]=1;
        }
        for(int i=s.size()-1;i>=0;i--)
        {
            for(int j=p.size()-1;j>=0;j--)
            {
                if(s[i]==p[j] || p[j]=='?')  prev[j]=curr[j+1];
                else if(p[j]=='*')
                {
                    prev[j]=(curr[j]||curr[j+1]||prev[j+1]);
                }
                else prev[j]=0;
            }
            curr=prev;
        }
        return curr[0];
    }
};
