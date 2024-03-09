//https://leetcode.com/problems/get-equal-substrings-within-budget/


class Solution {
public:
    /*int calc_cost(int b,int e,string s,string t)
    {
        int c=0;
        for(int k=b;k<e+1;k++)
        {
            c+=abs(s[k]-t[k]);
        }
        return c;
    }*/
    int equalSubstring(string s, string t, int maxCost) {
        int ans=0;
        vector<int> ps(s.size(),0);
        int sum=0;
        for(int i=0;i<s.size();i++){
            sum+=abs(s[i]-t[i]);
            ps[i]=sum;
        }
        for(int i=0;i<s.size();i++)
        {
            int l=i,h=s.size()-1;
            while(l<=h)
            {
                int m=(l+h)/2;
                int cost=ps[m];
                if(i!=0) cost-=ps[i-1];
                if(cost<=maxCost){
                    ans=max(ans,m-i+1);
                    l=m+1;
                }
                else h=m-1;
            }
        }
        return ans;
    }
};
