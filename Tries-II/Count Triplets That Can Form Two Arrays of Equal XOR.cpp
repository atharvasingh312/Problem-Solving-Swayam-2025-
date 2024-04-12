//https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/

class Trie{
   public:
   Trie* child[2];
   vector<int> ind;//store indexes jaha par same aaye xor
   Trie(){
    child[0]=NULL,child[1]=NULL;
   } 
};
void insert(int a,Trie* root,int ind)
{
    for(int i=31;i>=0;i--)
    {
        bool b=(a>>i)&1;
        if(root->child[b]==NULL) root->child[b]=new Trie();
        root=root->child[b];
    }
    //ye no. kaha kaha par present
    root->ind.push_back(ind);
}
vector<int> query(int a,Trie* root)
{
    for(int i=31;i>=0;i--)
    {
        bool b=(a>>i)&1;
        if(root->child[b]==NULL) return {};
        root=root->child[b];
    }
    return root->ind;
}
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        Trie* root=new Trie();
        int xr=0,c=0; 
        insert(0,root,-1);
        for(int i=0;i<arr.size();i++)
        {
            xr=(xr^arr[i]);
            vector<int> temp=query(xr,root);
            if(temp.size()){
                for(auto x:temp){
                    c+=(i-x-1);
                }
            }
            insert(xr,root,i);
        }
        return c;
    }
};

