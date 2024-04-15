//https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> st;
        vector<int> ans;
        for(auto x:edges){
            st.insert(x[1]);
        }
        for(int i=0;i<n;i++){
            if(!st.count(i)) ans.push_back(i);
        }
        return ans;
    }
};
