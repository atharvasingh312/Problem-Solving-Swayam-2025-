//https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/


int dfs(int s,vector<vector<int>> &adj,vector<int> &vis,int &mxdis){
    vis[s]=1;
    priority_queue<int> pq;
    int ans=0,c=2,r=0;
    for(auto x:adj[s]){
        if(!vis[x]){
            int l=1+dfs(x,adj,vis,mxdis);
            pq.push(l);
        }
    }
    while(!pq.empty() && c){
        if(r==0) r=pq.top(); 
        ans+=pq.top();
        pq.pop();
        c--;
    }
    mxdis=max(mxdis,ans);
    return r;
}
int Solution::solve(vector<int> &A) {
    int ans=0,mx=A.size();
    for(auto x:A) mx=max(mx,x+1);
    vector<vector<int>> adj(mx+1);
    vector<int> vis(mx+1);
    for(int i=0;i<A.size();i++){
        if(A[i]!=-1){
            adj[i].push_back(A[i]);
            adj[A[i]].push_back(i);
        }
    }
    int mxdis=0;
    int x=dfs(0,adj,vis,mxdis);
    return mxdis;
}
