//https://leetcode.com/problems/boats-to-save-people/


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int l=0,h=people.size()-1,x=0;
        while(l<=h)
        {
            if(people[l]+people[h]<=limit){
                l++;
                h--;
            }
            else if(people[l]>people[h]){
                l++;
            }
            else h--;
            x++;
        }
        return x;
    }
};
