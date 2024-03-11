//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/


class Solution {
public:
    bool check(int d,vector<int>& bloomDay,int k,int n)
    {
        int numb=0;//number of bouquet
        for(int i=0;i<bloomDay.size();i++)
        {
            int c=0;
            if(bloomDay[i]<=d){
                while(i<bloomDay.size() && bloomDay[i]<=d){
                    c++;
                    i++;
                    if(c==k){
                        c=0;
                        numb++;
                    }
                }
                i--;
            }
        }
        if(numb>=n) return true;
        else        return false;
    }
    int minDays(vector<int>& bloomDay, int n, int k) {
        int l=INT_MAX,h=INT_MIN;
        for(int i=0;i<bloomDay.size();i++)
        {
            l=min(l,bloomDay[i]);
            h=max(h,bloomDay[i]);
        }
        int ans=-1;
        while(l<=h)
        {
            //cout<<l<<" "<<h<<endl;
            int m=(l+h)/2;
            if(check(m,bloomDay,k,n)){
                ans=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};
