//https://leetcode.com/problems/sum-of-prefix-scores-of-strings/

class Trie{
    public:
    int count;
    Trie* child[26];
    Trie(){
        count=0;
        for(int i=0;i<26;i++) child[i]=NULL;
    }
};
void insert(string &word,Trie* root)
{
    for(int i=0;i<word.size();i++)
    {
        if(root->child[word[i]-'a']==NULL){
            root->child[word[i]-'a']=new Trie();
        }
        root=root->child[word[i]-'a'];
        root->count++;
    }
}
int findcount(string &word,Trie* root)
{
    int c=0;
    for(int i=0;i<word.size();i++)
    {
        root=root->child[word[i]-'a'];
        c+=root->count;
    }
    return c;
}
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie *t=new Trie();
        vector<int> ans;
        for(int i=0;i<words.size();i++)
        {
            insert(words[i],t);
        }
        for(int i=0;i<words.size();i++){
            ans.push_back(findcount(words[i],t));
        }
        return ans;
    }
};
