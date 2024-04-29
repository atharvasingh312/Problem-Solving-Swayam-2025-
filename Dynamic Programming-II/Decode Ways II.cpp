//https://leetcode.com/problems/decode-ways-ii/

class Solution {
public:
    int solve(int i,int n,string &s, vector<vector<int>> &dp){
        int mod=1e9+7;
        if(i==s.size())       return 1;
        else if(dp[i][n]!=-1) return dp[i][n];
        int c=0,k=0;
        if(s[i]=='*'){
            for(int k=1;k<=9;k++){
                c=(c+solve(i+1,k,s,dp))%mod;
                if(n!=0 && n*10+k<=26) c=(c+solve(i+1,n*10+k,s,dp))%mod;
            }
        }
        else{
            if(s[i]!='0')
            c+=solve(i+1,s[i]-'0',s,dp);
            if(n!=0){
                int nn=n*10+(s[i]-'0');
                if(nn<=26) c=(c+solve(i+1,nn,s,dp))%mod;
            }
        }
        return  dp[i][n]=c;
    }
    int numDecodings(string s) {
        vector<vector<int>> dp(s.size()+1,vector<int>(27,-1));
        return solve(0,0,s,dp);
    }
};
