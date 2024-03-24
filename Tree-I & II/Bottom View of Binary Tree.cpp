

class Solution {
  public:
    void solve(Node* root,map<int,int> &mp)
    {
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                Node* f=q.front().first;
                int v=q.front().second;
                q.pop();
                mp[v]=f->data;
                if(f->left)  q.push({f->left,v-1});
                if(f->right) q.push({f->right,v+1});
            }
        }
    }
    vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int,int> mp;
        solve(root,mp);
        vector<int> ans;
        for(auto x:mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};
