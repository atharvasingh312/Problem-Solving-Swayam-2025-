//https://leetcode.com/problems/path-with-minimum-effort/


class Solution {
public:
    int solve(vector<vector<int>>& heights,vector<vector<int>> path,vector<vector<int>>& dis)
    {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        dis[0][0]=0;
        q.push({0,0,0});
        while(!q.empty()){
            int i=q.top()[1];
            int j=q.top()[2];
            int cur_effort=q.top()[0];
            q.pop();
            for(int k=0;k<4;k++){
                int x=path[k][0]+i;
                int y=path[k][1]+j;
                if(x>=0 && x<n && y>=0 && y<m)
                {
                    int e=max(cur_effort,abs(heights[x][y]-heights[i][j]));
                    if(dis[x][y]>e){
                        dis[x][y]=e;
                        q.push({dis[x][y],x,y});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> path={{-1,0},{1,0},{0,1},{0,-1}};
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        return solve(heights,path,dis);
    }
};
