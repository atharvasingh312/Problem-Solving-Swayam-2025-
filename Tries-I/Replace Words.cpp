//https://leetcode.com/problems/replace-words/description/

class Trie{
    public:
    bool isend;
    vector<Trie*> child;
    Trie(){
        isend=0;
        child.resize(26,NULL);
    }
};
void insert(string x,Trie* root)
{
    for(int i=0;i<x.size();i++)
    {
        if(root->child[x[i]-'a']==NULL)
        {
            root->child[x[i]-'a']=new Trie();
        }
        root=root->child[x[i]-'a'];
    }
    root->isend=1;
}
string query(string x,Trie* root)
{
    string temp;
    for(int i=0;i<x.size();i++)
    {
        temp.push_back(x[i]);
        if(root->child[x[i]-'a']==NULL) return x;
        root=root->child[x[i]-'a'];
        if(root->isend==1) return temp;
    }
    return temp;
}
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* root=new Trie();
        for(int i=0;i<dictionary.size();i++)
        insert(dictionary[i],root);
        string temp="",ans="";
        for(int i=0;i<sentence.size();i++)
        {
            if(sentence[i]==' ')
            {
                ans+=query(temp,root);
                ans+=' ';
                temp="";
            }
            else                 temp.push_back(sentence[i]);
        }
        ans+=query(temp,root);
        return ans;
    }
};
