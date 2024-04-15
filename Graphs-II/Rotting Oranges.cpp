//https://leetcode.com/problems/rotting-oranges/


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        //first all rotten oranges become our strating point
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    grid[i][j]=0;
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int count;
        q.size()?count=0:count=1;
        vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int x1=x+dir[k][0];
                    int y1=y+dir[k][1];
                    if(x1<m && y1<n && x1>=0 && y1>=0 && !vis[x1][y1] && grid[x1][y1]==1)
                    {
                        vis[x1][y1]=1;
                        grid[x1][y1]=2;
                        q.push({x1,y1});
                    }
                }
            }
            count++;
        }
        for(auto x:grid)
        for(auto y:x)
        if(y==1) return -1;
        return count-1;
    }
};
