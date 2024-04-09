//https://leetcode.com/problems/longest-common-suffix-queries/

class Trie{
    public:
    bool isend;
    int index;//earliest index of elemnt that can be found
    Trie* child[26];
    Trie(){
        isend=0;
        index=INT_MAX;
        for(int i=0;i<26;i++) child[i]=NULL;
    }
};
void insert(int ind,string x,Trie* root,vector<string>& wordsContainer)
{
    for(int i=x.size()-1;i>=0;i--)
    {
        if(root->child[x[i]-'a']==NULL)
        {
            root->child[x[i]-'a']=new Trie();
        }
        root=root->child[x[i]-'a'];
        if(root->index==INT_MAX || wordsContainer[root->index].size()>x.size()) root->index=ind;
    }
    root->isend=1;
}
int query(string x,Trie* root)
{
    for(int i=x.size()-1;i>=0;i--)
    {
        if(root->child[x[i]-'a']==NULL) return root->index;
        root=root->child[x[i]-'a'];
    }
    return root->index;
}
class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie* root=new Trie();
        int ind=0,mn=INT_MAX;
        for(int i=0;i<wordsContainer.size();i++){
            insert(i,wordsContainer[i],root,wordsContainer);
            if(mn>wordsContainer[i].size()){
                mn=wordsContainer[i].size();
                ind=i;//ans jab kuch na match ho
            }
        }
        vector<int> ans;
        for(int i=0;i<wordsQuery.size();i++)
        {
            ans.push_back(query(wordsQuery[i],root));
            if(ans[i]==INT_MAX) ans[i]=ind;
        }
        return ans;
    }
};
