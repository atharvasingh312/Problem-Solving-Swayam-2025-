//https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int s,vector<vector<int>> &adj,vector<int> &vis,stack<int> & st){
	    vis[s]=1;
	    for(auto x:adj[s])
	    if(!vis[x])
	    dfs(x,adj,vis,st);
	    st.push(s);
	}
	void dfs1(int s,vector<vector<int>> &adj,vector<int> &vis){
	    vis[s]=1;
	    for(auto x:adj[s])
	    if(!vis[x])
	    dfs1(x,adj,vis);
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        //reverse edges:
        vector<vector<int>> nadj(V);
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto x:adj[i]){
                nadj[x].push_back(i);
            }
        }
        int c=0;
        while(!st.empty()){
            if(!vis[st.top()]){
                c++;
                dfs1(st.top(),nadj,vis);
            }
            st.pop();
        }
        return c;
    }
};
