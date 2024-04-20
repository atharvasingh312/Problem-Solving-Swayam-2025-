//https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/


class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n,0);
        vector<vector<int>> adj(n);
        vector<set<int>> ans(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            indeg[edges[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!indeg[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(auto x:adj[f]){
                for(auto y:ans[f]){
                    ans[x].insert(y);
                }
                ans[x].insert(f);
                indeg[x]--;
                if(!indeg[x]) q.push(x);
            }
        }
        vector<vector<int>> an(n);
        for(int i=0;i<n;i++){
            for(auto y:ans[i]){
                an[i].push_back(y);
            }
        }
        return an;
    }
};
