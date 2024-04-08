//https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

class Trie{
    public:
    Trie* child[2];
    Trie(){
        for(int i=0;i<2;i++) child[i]=NULL;
    }
};
void insert(int a,Trie* root)
{
    for(int i=31;i>=0;i--)
    {
        bool b=((a>>i)&1);
        if(root->child[b]==NULL) root->child[b]=new Trie();
        root=root->child[b];
    }
}
int query(int a,Trie* root)
{
    int ans=0;
    for(int i=31;i>=0;i--)
    {
        bool b=((a>>i)&1);
        if(root->child[1-b]!=NULL){
            ans+=(1<<i);
            root=root->child[1-b];
        }
        else root=root->child[b];
    }
    return ans;
}
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) 
    {
        int ans=0;
        Trie* root=new Trie();
        insert(nums[0],root);
        for(int i=1;i<nums.size();i++)
        {
            ans=max(ans,query(nums[i],root));
            insert(nums[i],root);
        }
        return ans;
    }
};
