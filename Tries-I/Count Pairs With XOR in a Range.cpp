//https://leetcode.com/problems/count-pairs-with-xor-in-a-range/

class Trie{
    public:
    int count;
    Trie* child[2];
    Trie(){
        count=0;
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
        root->count++;
    }
}
int query(int l,int a,Trie* root,int bit)
{
    if(bit==-1) return root->count;
    int count=0;
    bool b=((a>>bit)&1);
    bool c=((l>>bit)&1);
    if(root->child[0]!=NULL)
    {
        if((b^0)<c)        count+=root->child[0]->count;
        else if((b^0)==c)  count+=query(l,a,root->child[0],bit-1);
    }
    if(root->child[1]!=NULL)
    {
        if((b^1)<c)        count+=root->child[1]->count;
        else if((b^1)==c)  count+=query(l,a,root->child[1],bit-1);
    }
    return count;
}
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int c=0;
        Trie* root=new Trie();
        for(int i=0;i<nums.size();i++)
        {
            int numg=query(high,nums[i],root,31);
            int numl=query(low-1,nums[i],root,31);
            c+=numg-numl;
            insert(nums[i],root);
        }
        return c;
    }
};
