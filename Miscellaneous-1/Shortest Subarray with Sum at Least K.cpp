//https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/


class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long long,long long>> dq;
        dq.push_back({0,-1});
        long long sum=0,mn=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(!dq.empty() && dq.back().first>sum){
                dq.pop_back();
            }
            dq.push_back({sum,i});
            while(!dq.empty() && dq.back().first-dq.front().first>=k){
                mn=min(mn,dq.back().second-dq.front().second);
                dq.pop_front();
            }
        }
        while(!dq.empty() && dq.back().first-dq.front().first>=k){
            mn=min(mn,dq.back().second-dq.front().second);
            dq.pop_front();
        }
        if(mn==INT_MAX) return -1;
        return mn;
    }
};
