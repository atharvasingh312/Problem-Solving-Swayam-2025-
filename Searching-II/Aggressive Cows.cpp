//https://www.geeksforgeeks.org/problems/aggressive-cows/1


class Solution {
public:
    bool check(int d,vector<int> &stalls,int k)
    {
        k--;
        int lp=stalls[0];//last_placed_cow
        for(int i=1;i<stalls.size() && k;i++)
        {
            if(stalls[i]-lp>=d){
                k--;
                lp=stalls[i];
            }
        }
        if(k==0) return true;
        else     return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        int mx=INT_MIN,mn=INT_MAX;
        for(auto x:stalls)
        {
            mx=max(mx,x);
            mn=min(mn,x);
        }
        int l=1,h=mx-mn;
        sort(stalls.begin(),stalls.end());
        //geussing the min distance between cow
        int ans=h;
        while(l<=h)
        {
            int m=(l+h)/2;
            if(check(m,stalls,k)){
                ans=m;    
                l=m+1;
            }
            else h=m-1;
        }
        return ans;
    }
};
