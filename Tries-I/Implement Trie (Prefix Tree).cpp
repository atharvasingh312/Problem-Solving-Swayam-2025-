//https://leetcode.com/problems/implement-trie-prefix-tree/description/

class Trie {
class Node{
    public:
    bool isend;
    vector<Node*> child;
    Node(){
        isend=0;
        child.resize(26,NULL);
    }
};
public:
    Node* root,* temp;
    Trie() {
        root=new Node();
    }
    void insert(string word) {
        temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->child[word[i]-'a']==NULL){
                temp->child[word[i]-'a']=new Node();
            }
            temp=temp->child[word[i]-'a'];
        }
        temp->isend=1;
    }
    bool search(string word) {
        temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->child[word[i]-'a']==NULL) return 0;
            temp=temp->child[word[i]-'a'];
        }
        if(temp->isend==1) return true;
        else              return false;
    }
    bool startsWith(string prefix) {
        temp=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(temp->child[prefix[i]-'a']==NULL) return 0;
            temp=temp->child[prefix[i]-'a'];
        }
        return 1;
    }
};
