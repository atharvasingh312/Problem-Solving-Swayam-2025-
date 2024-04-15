//https://www.interviewbit.com/problems/valid-path/


bool ispossible(int x,int y,int n,int r,vector<int> & bx,vector<int> &by){
    for(int i=0;i<n;i++){
        double l=sqrt((double)(pow(bx[i]-x,2)+pow(by[i]-y,2)));
        if(l<=r) return false;
    }
    return true;
}
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    queue<vector<int>> q;
    vector<vector<int>> vis(A+1,vector<int>(B+1,0));
    q.push({0,0});
    vis[0][0]=1;
    while(!q.empty()){
        int x=q.front()[0];
        int y=q.front()[1];
        q.pop();
        if(x==A && y==B) return "YES";
        vector<vector<int>> dir={{0,-1},{0,1},{1,0},{-1,0}};
        for(int i=0;i<4;i++){
            int u=x+dir[i][0];
            int v=y+dir[i][1];
            if(u>=0 && v>=0 && u<A+1 && v<B+1 && !vis[u][v] && ispossible(u,v,C,D,E,F)){
                q.push({u,v});
                vis[u][v]=1;
            }
        }
    }
    return "NO";
}
