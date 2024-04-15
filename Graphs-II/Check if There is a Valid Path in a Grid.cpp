//https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/


class Solution {
public:
    //0 right 1 up 2 down 3 left
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &vis,int prev){
        int m=grid.size(),n=grid[0].size();
        int u=i,v=j,next=-1;
        if(grid[i][j]==1){
            if(prev==-1 || prev==0)   v=j+1;
            else if(prev==3)          v=j-1;
        }
        else if(grid[i][j]==2){
            if(prev==-1 || prev==2)    u=i+1;
            else if(prev==1)           u=i-1;
        }
        else if(grid[i][j]==3){
            if(prev==-1 || prev==0)  u=i+1;
            else if(prev==1)         v=j-1;
        }
        else if(grid[i][j]==4){
            if(prev==-1){
                dfs(u,v+1,grid,vis,0);
                dfs(u+1,v,grid,vis,2);
                return;
            }
            else if(prev==3)             u=i+1;
            else if(prev==1)             v=j+1;
        }
        else if(grid[i][j]==5){
            if(prev==0)        u=i-1;
            else if(prev==2)   v=j-1;
        }
        else{
            if(prev==-1 || prev==2) v=j+1;
            else if(prev==3)        u=i-1;
        }
       if(u==i && v==j) return;
        vis[i][j]=1;
        if (v-j==1) next=0;
        else if(j-v==1) next=3;
        else if(u-i==1) next=2;
        else if(i-u==1) next=1;
        if(u>=0 && v>=0 && u<m && v<n && !vis[u][v])
        dfs(u,v,grid,vis,next);
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        dfs(0,0,grid,vis,-1);
        if(vis[grid.size()-1][grid[0].size()-1]) return true;
        return false;
    }
};
