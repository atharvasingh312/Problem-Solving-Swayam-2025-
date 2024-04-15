//https://www.interviewbit.com/problems/knight-on-chess-board/

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    vector<vector<int>> vis(A,vector<int>(B,0));
    queue<vector<int>> q;
    q.push({C-1,D-1});
    vis[C-1][D-1]=1;
    vector<vector<int>> dir={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,2},{1,-2},{2,-1},{2,1}};
    int c=0;
    while(!q.empty())
    {
        int sz=q.size();
        while(sz--){
        int x=q.front()[0];
        int y=q.front()[1];
        q.pop();
        if(x==E-1 && y==F-1) return c;
        for(int i=0;i<8;i++)
        {
            int u=x+dir[i][0],v=y+dir[i][1];
            if(u>=0 && v>=0 && u<A && v<B && !vis[u][v]){
                q.push({u,v});
                vis[u][v]=1;
            }
        }
        }
        c++;
    }
    return -1;
}
