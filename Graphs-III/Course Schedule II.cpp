//https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int n,vector<vector<int>>& prerequisites) {
        //first detect cycle
        vector<int> ans;
        vector<int> indeg(n,0);
        vector<int> vis(n,0);
        vector<vector<int>> adj(n,vector<int>());
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!indeg[i]){
                q.push(i);
                vis[i]=1;
            }
        }
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            ans.push_back(t);
            for(auto x:adj[t])
            {
                if(--indeg[x]==0)
                {
                    q.push(x);
                    vis[x]=1;
                }
            }
        }
        if(ans.size()==n) return ans;
        else              return {};
    }
};
