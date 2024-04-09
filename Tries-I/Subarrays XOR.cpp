//https://www.hackerearth.com/problem/algorithm/subarrays-xor/

#include <bits/stdc++.h>
using namespace std;
#define int long long
 
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
    for(int i=63;i>=0;i--)
    {
        bool b=((a>>i)&1);
        if(root->child[b]==NULL) root->child[b]=new Trie();
        root=root->child[b];
        root->count++;
    }
}
int query(int l,int a,Trie* root,int bit)
{
    if(bit==-1) return 0;
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
        else if((b^1)==c)   count+=query(l,a,root->child[1],bit-1);
    }
    return count;
}
signed main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
        Trie* root=new Trie();
		int x,inp=0;
        int c=0;
        insert(inp,root);
		for(int i=0;i<n;i++)
		{
			cin>>x;
            inp=(inp^x);
            c+=query(k,inp,root,63);
            insert(inp,root);
		}
        cout<<c<<endl;
	}
}
