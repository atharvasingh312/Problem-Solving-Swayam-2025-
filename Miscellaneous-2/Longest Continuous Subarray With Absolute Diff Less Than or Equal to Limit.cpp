//https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<int,vector<int>,greater<int>> mnpq;
        priority_queue<int> mxpq;
        int j=0,ans=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            mxpq.push(nums[i]);
            mnpq.push(nums[i]);
            while(j<=i && mxpq.top()-mnpq.top()>limit){
                mp[nums[j++]]--;
                if(mp[nums[j-1]]==0) mp.erase(nums[j-1]);
                while(mp.find(mxpq.top())==mp.end()){
                    mxpq.pop();
                }
                while(mp.find(mnpq.top())==mp.end()){
                    mnpq.pop();
                }
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};
