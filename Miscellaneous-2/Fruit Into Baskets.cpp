//https://leetcode.com/problems/fruit-into-baskets/description/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int b=0,ans=0;
        for(int i=0;i<fruits.size();i++){
            mp[fruits[i]]++;
            while(mp.size()>2){
                mp[fruits[b++]]--;
                if(mp[fruits[b-1]]==0) mp.erase(fruits[b-1]);
            }
            ans=max(ans,i-b+1);
        }
        return ans;
    }
};
