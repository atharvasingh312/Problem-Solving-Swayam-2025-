//https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& boards,vector<vector<int>>& vis)
    {
        int m=boards.size();
        int n=boards[0].size();
        vis[i][j]=1;
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(int k=0;k<4;k++)
        {
            int x=i+dir[k][0];
            int y=j+dir[k][1];
            if(x>=0 && y>=0 && x<m && y<n && !vis[x][y] && boards[x][y]=='O')
            dfs(x,y,boards,vis);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && (i==0 || j==0 || i==m-1 ||j==n-1) && board[i][j]=='O')
                {
                    dfs(i,j,board,vis);
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j])
                {
                    board[i][j]='X';
                }
            }
        }
    }
};
