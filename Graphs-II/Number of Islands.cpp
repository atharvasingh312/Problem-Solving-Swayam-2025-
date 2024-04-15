//https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>> &grid)
    {
        vis[i][j]=1;
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        for(int k=0;k<4;k++){
            int x=i+dir[k][0],y=j+dir[k][1];
            if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]=='1' && !vis[x][y]){
                dfs(x,y,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int c=0,m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    c++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return c;
    }
};
