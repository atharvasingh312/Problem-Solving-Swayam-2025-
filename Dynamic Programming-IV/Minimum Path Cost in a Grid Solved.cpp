//https://leetcode.com/problems/minimum-path-cost-in-a-grid/description/


class Solution {
public:
int solve(vector<vector<int>>& g,vector<vector<int>>& mo,int i,int prev,vector<vector<int>> &dp)
{
    if(i==g.size()) return 0;
    else if(dp[i][prev+1]!=-1) return dp[i][prev+1]; 
    int ans=INT_MAX;
    for(int k=0;k<g[0].size();k++){
        if(prev==-1){
            ans=min(ans,g[i][k]+solve(g,mo,i+1,k,dp));
        }
        else{
            ans=min(ans,g[i][k]+mo[g[i-1][prev]][k]+solve(g,mo,i+1,k,dp));
        }
    }
    return dp[i][prev+1]=ans;
}
    int minPathCost(vector<vector<int>>& g, vector<vector<int>>& mo) {
        vector<vector<int>> dp(g.size()+1,vector<int>(g[0].size()+1,0));
        //return solve(grid,moveCost,0,-1,dp);
        for(int j=0;j<g[0].size();j++){
            dp[g.size()-1][j]=g[g.size()-1][j];
        }
        for(int i=g.size()-2;i>=0;i--){
            for(int j=0;j<g[0].size();j++){
                int ans=INT_MAX;
                for(int k=0;k<g[0].size();k++){
                    ans=min(ans,g[i][j]+mo[g[i][j]][k]+dp[i+1][k]);
                }
                dp[i][j]=ans;
            }
        }
        int mn=INT_MAX;
        for(int i=0;i<g[0].size();i++){
            mn=min(mn,dp[0][i]);
        }
        return mn;
    }
};
