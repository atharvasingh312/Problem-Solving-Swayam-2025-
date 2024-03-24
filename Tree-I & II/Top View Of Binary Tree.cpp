//https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1


class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> v;
        map<int,int> mp;
        queue<pair<int,Node*>> q;
        q.push({0,root});
        while(!q.empty())
        {
            int sz=q.size();
            for(int k=0;k<sz;k++)
            {
                Node* f=q.front().second;
                int x=q.front().first;
                q.pop();
                if(mp.find(x)==mp.end())
                mp[x]=f->data;
                if(f->left) q.push({x-1,f->left});
                if(f->right) q.push({x+1,f->right});
            }
        }
        for(auto x:mp)
        {
            v.push_back(x.second);
        }
        return v;
    }

};
