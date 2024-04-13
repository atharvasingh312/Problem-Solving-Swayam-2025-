//https://www.geeksforgeeks.org/problems/search-query-auto-complete/1

unordered_map<string,int> mp;
unordered_map<int,string> mp2;

bool custom(int a,int b){
    if(mp[mp2[a]]>mp[mp2[b]]) return true;
    else if(mp[mp2[a]]<mp[mp2[b]]) return false;
    else
    {
        if(mp2[a]<=mp2[b]) return true;
        else               return false;
    }
}

class AutoCompleteSystem {
public:
    class Trie{
        public:
        Trie* child[27];
        vector<int> v;
        Trie(){
            for(int i=0;i<27;i++) child[i]=NULL;
        }
    };
    void insert(string x,int ind,Trie* root){
        for(int i=0;i<x.size();i++)
        {
            if(x[i]==' '){
                if(root->child[26]==NULL) root->child[26]=new Trie();
                root=root->child[26];
            }else{
                if(root->child[x[i]-'a']==NULL) root->child[x[i]-'a']=new Trie();
                root=root->child[x[i]-'a'];
            }
            root->v.push_back(ind);
        }
    }
    vector<int> query(string x,Trie* root){
        for(int i=0;i<x.size();i++)
        {
            if(x[i]==' '){
                if(root->child[26]==NULL) return {};
                root=root->child[26];
            }else{
                if(root->child[x[i]-'a']==NULL) return {};
                root=root->child[x[i]-'a'];
            }
        }
        return root->v;
    }
    

    Trie* root=new Trie();
    string s="";
    int n=0;
    
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        mp.clear();
        mp2.clear();
        for(int i=0;i<sentences.size();i++)
        {
            mp[sentences[i]]=times[i];
            mp2[i]=sentences[i];
            insert(sentences[i],i,root);
        }
        n=sentences.size();
    }
    
    vector<string> input(char c) {
        // write code to return the top 3 suggestions when the current character in the stream is c
        // c == '#' means , the current query is complete and you may save the entire query into
        // historical data
        if(c=='#'){
            if(mp.find(s)==mp.end()){
                mp2[n]=s;
                insert(s,n,root);
                n++;
            }
            mp[s]++;    
            s="";
            return {};
        }
        s+=c;
        vector<int> temp=query(s,root);
        sort(temp.begin(),temp.end(),custom);
        vector<string> ans;
        for(int i=0;i<3 && i<temp.size();i++){
            ans.push_back(mp2[temp[i]]);
        }
        return ans;
    }
};

/**
 * Your AutoCompleteSystem object will be instantiated and called as such:
 * AutoCompleteSystem* obj = new AutoCompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
