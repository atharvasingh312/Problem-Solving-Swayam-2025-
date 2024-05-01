//https://leetcode.com/problems/number-of-visible-people-in-a-queue/description/

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        vector<int> ans(heights.size(),0);
        for(int i=heights.size()-1;i>=0;i--){
            int c=0;
            while(!st.empty() && st.top()<heights[i]){
                st.pop();
                c++;
            }
            if(st.size()) ans[i]++;
            ans[i]+=c;
            st.push(heights[i]);
        }
        return ans;
    }
};
