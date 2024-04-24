//https://leetcode.com/problems/path-with-maximum-probability/


class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<vector<double>>> adj(n+1);
        vector<double> prob(n+1,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({(double)edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({(double)edges[i][0],succProb[i]});
        }
        priority_queue<vector<double>> pq;
        prob[start_node]=1;
        pq.push({1.0,(double)start_node});
        while(!pq.empty()){
            double node=pq.top()[1];
            double d=pq.top()[0];
            pq.pop();
            for(auto x:adj[node]){
                if(prob[x[0]]<d*x[1]){
                    prob[x[0]]=d*x[1];
                    pq.push({prob[x[0]],x[0]});
                }
            }
        }
        return prob[end_node];
    }
};
