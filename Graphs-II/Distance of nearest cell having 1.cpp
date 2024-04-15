//https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1


class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int m=grid.size(),n=grid[0].size();
	    vector<vector<int>> vis(m,vector<int>(n,-1));
	    queue<pair<int,int>> q;
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(grid[i][j]==1){
	                q.push({i,j});
	                vis[i][j]=0;
	            }
	        }
	    }
	    int c=1;
	    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
	    while(!q.empty()){
	        int sz=q.size();
	        for(int k=0;k<sz;k++)
	        {
	            int x=q.front().first;
	            int y=q.front().second;
	            q.pop();
	            for(int i=0;i<4;i++){
	                int u=x+dir[i][0],v=y+dir[i][1];
	                if(u>=0 && v>=0 && u<m && v<n && vis[u][v]==-1){
	                    vis[u][v]=c;
	                    q.push({u,v});
	                }
	            }
	        }
	        c++;
	    }
	    return vis;
	}
};
