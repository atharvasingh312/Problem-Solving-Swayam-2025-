//https://www.geeksforgeeks.org/auto-complete-feature-using-trie/


#include <bits/stdc++.h>
using namespace std;

class Trie{
    public:
    bool isend;
    vector<int> index;//all index who have prefix;
    Trie* child[26];
    Trie(){
        isend=0;
        for(int i=0;i<26;i++) child[i]=NULL;
    }
};
void insert(int ind,Trie* root,string x)
{
    for(int i=0;i<x.size();i++)
    {
        if(root->child[x[i]-'a']==NULL)
        {
            root->child[x[i]-'a']=new Trie();
        }
        root=root->child[x[i]-'a'];
        root->index.push_back(ind);
    }
    root->isend=1;
}
vector<int> query(string x,Trie* root)
{
    for(int i=0;i<x.size();i++)
    {
        if(root->child[x[i]-'a']==NULL) return {};//empty
        root=root->child[x[i]-'a'];
    }
    return root->index;
}
int main()
{
    
    Trie* root=new Trie();
    vector<string> words={"hello","dog","hell","cat","a","hel","help","helps","helping"};
    for(int i=0;i<words.size();i++)
    {
        insert(i,root,words[i]);
    }
    string x;
    cout<<"Search:"<<endl;
    cin>>x;
    vector<int> ans=query(x,root);//indices of all suggestions
    cout<<"Seggestions:"<<endl;
    for(auto x:ans) cout<<words[x]<<endl;
    return 0;
}
