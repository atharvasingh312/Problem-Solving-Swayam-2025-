//https://leetcode.com/problems/clone-graph/description/


class Solution {
public:
    Node* solve(Node* node, unordered_map<Node*,Node*>& mp)
    {
        if(node==NULL) return NULL;
        if(mp.find(node)==mp.end())
        {
            Node* new1=new Node(node->val);
            mp[node]=new1;
            for(auto it:node->neighbors)
            {
                if(mp.find(it)!=mp.end()){
                (new1->neighbors).push_back(mp[it]);
                }
                else{
                new1->neighbors.push_back(solve(it,mp));
                }
            }
            return new1; 
        }
        return NULL;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        Node* ans=solve(node,mp);
        return ans;
    }
};
