//https://www.geeksforgeeks.org/maximum-profit-sale-wines/

#include <bits/stdc++.h>
using namespace std;

int solve(int i,int y,vector<int> &arr,vector<vector<int>> &dp,vector<int> & ans)
{
    int j=arr.size()-1-(y-i);
    if(i==j) return arr[i]*(y+1);
    else if(dp[i][y]!=-1) return dp[i][y]; 
    int l=(y+1)*arr[i]+solve(i+1,y+1,arr,dp,ans),r=(y+1)*arr[j]+solve(i,y+1,arr,dp,ans);
    if(l<r) ans[i]=1;
    else     ans[i]=0;
    return dp[i][y]=max(l,r);
}
int main()
{
    vector<int> arr={2,4,6,2,5};
    vector<int> ans(arr.size(),0);
    vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),0));
    //solve(0,0,arr,dp,ans);
    for(int i=arr.size()-1;i>=0;i--){
        for(int y=arr.size()-1;y>=0;y--){
            int j=arr.size()-1-(y-i);
            if(j>=0 && j<arr.size()){
            if(i==j) dp[i][y]=arr[i]*(y+1);
            else{
                int l=(y+1)*arr[i]+dp[i+1][y+1],r=(y+1)*arr[j]+dp[i][y+1];
                if(l<r)  ans[i]=1;
                else     ans[i]=0;
                dp[i][y]=max(l,r);
            }
            }
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]==0) cout<<"beg"<<" ";
        else cout<<"end"<<" ";
    }
    return 0;
}
