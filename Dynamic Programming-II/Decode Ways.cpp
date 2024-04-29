//https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int solve(int i,string &s, vector<int> &dp){
        if(i==s.size()) return 1;
        else if(s[i]=='0') return 0;
        else if(dp[i]!=-1) return dp[i];
        int n=0,c=0;
        for(int j=i;j<s.size() && n<=26;j++){
            n=n*10+(s[j]-'0');
            if(n<=26)
            c+=solve(j+1,s,dp);
        }
        return  dp[i]=c;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,0);
        dp[s.size()]=1;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='0') continue;
            int n=0;
            for(int j=i;j<s.size() && n<=26;j++){
                n=n*10+(s[j]-'0');
                if(n<=26)
                dp[i]+=dp[j+1];
            }
        }
        return dp[0];
    }
};
