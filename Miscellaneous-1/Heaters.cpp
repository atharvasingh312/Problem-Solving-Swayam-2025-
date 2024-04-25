//https://leetcode.com/problems/heaters/

class Solution {
public:
    bool check(int r,vector<int>& houses, vector<int>& heaters)
    {
        int hea=0;
        int i=0;
        while(i<houses.size())
        {
            if(hea>=heaters.size()) return 0;
            else if(abs(heaters[hea]-houses[i])>r) hea++;
            else i++;
        }
        return 1;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int l=0,h=1e9,m=0;
        while(l<=h){
            m=(l+h)/2;
            if(check(m,houses,heaters)) h=m-1;
            else                        l=m+1;
        }
        return l;
    }
};
