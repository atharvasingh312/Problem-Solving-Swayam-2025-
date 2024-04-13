//https://www.geeksforgeeks.org/problems/phone-directory4628/1


class Solution{
public:
    class Trie{
        public:
        Trie* child[26];
        vector<int> ind;
        Trie(){
            for(int i=0;i<26;i++) child[i]=NULL;
        }
    };
    void insert(string x,int ind,Trie* root){
        for(int i=0;i<x.size();i++)
        {
            if(root->child[x[i]-'a']==NULL) root->child[x[i]-'a']=new Trie();
            root=root->child[x[i]-'a'];
            root->ind.push_back(ind);
        }
    }
    vector<int> query(string x,Trie* root){
        for(int i=0;i<x.size();i++)
        {
            if(root->child[x[i]-'a']==NULL) return {};
            root=root->child[x[i]-'a'];
        }
        return root->ind;
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie* root=new Trie();
        set<string> st;
        unordered_map<int,string> mp;
        int k=0;
        for(int i=0;i<n;i++)
        {
            st.insert(contact[i]);
        }
        for(auto x:st)
        {
            insert(x,k,root);
            mp[k]=x;
            k++;
        }
        string temp="";
        vector<vector<string>> ans;
        for(int i=0;i<s.size();i++)
        {
            temp+=s[i];
            vector<string> x; 
            vector<int> ind=query(temp,root);
            if(ind.size()==0) x.push_back("0");
            for(int i=0;i<ind.size();i++)
            {
                x.push_back(mp[ind[i]]);
            }
            ans.push_back(x);
        }
        return ans;
    }
};
