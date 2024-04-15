//https://leetcode.com/problems/number-of-provinces/


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
    int count=0;
    int n=isConnected.size();
    vector<int> vis(n,0);
    for (int i = 0; i < n; i++) {
      if (vis[i]==0) 
      {
          count++;
          vis[i]=1;
          queue<int> q;
          q.push(i);
          while (!q.empty()) {
              int t=q.front();
              q.pop();
              for (int j = 0; j < n; j++) {
                if (isConnected[t][j] ==1 && vis[j]==0) {
                    vis[j]=1;
                    q.push(j);
                }
              }
          }
      }
    }
    return count;
    }
};
