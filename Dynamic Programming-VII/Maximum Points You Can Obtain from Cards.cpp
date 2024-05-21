//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int solve(int i,int j,vector<int>& cardPoints, int k,vector<vector<int>> &dp)
    {
        int n=cardPoints.size();
        if(i+(n-1-j)==k) return 0;
        else if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=max(cardPoints[j]+solve(i,j-1,cardPoints,k,dp),cardPoints[i]+solve(i+1,j,cardPoints,k,dp));
    }
    int maxScore(vector<int>& cardPoints, int k)
    {
        /*int n=cardPoints.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        //return solve(0,cardPoints.size()-1,cardPoints,k,dp);
        for(int i=n-2;i>=0;i--)
        {
            for(int j=1;j<n;j++)
            {
                if(i>j) continue;
                if(i+(n-1-j)==k) dp[i][j]=0;
                else
                {
                    dp[i][j]=max(cardPoints[j]+dp[i][j-1],cardPoints[i]+dp[i+1][j]);
                }
            }
        }
        return dp[0][n-1];*/
        //dynamic programming wont work
        int ws=cardPoints.size()-k;
        int b=0,e=0,sum=0,mx=INT_MAX,ts=0;
        while(e<ws){
            sum+=cardPoints[e];
            ts+=cardPoints[e];
            e++;
        }
        mx=min(mx,sum);
        while(e<cardPoints.size()){
            sum+=cardPoints[e]-cardPoints[b];
            ts+=cardPoints[e];
            b++;
            e++;
            mx=min(mx,sum);
        }
        return ts-mx;
    }
};
