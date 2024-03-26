//https://www.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* findLca(Node* root, int a, int b){
        if(!root || root->data==a || root->data==b) return root;
        Node* l=findLca(root->left,a,b);
        Node* r=findLca(root->right,a,b);
        if(l && r) return root;
        else if(l) return l;
        return r;
    }
    bool find(Node* r,int x,int &l)
    {
        if(!r) return 0;
        else if(r->data==x) return 1;
        l++;
        if(find(r->left,x,l)) return true;
        if(find(r->right,x,l)) return true;
        l--;
        return false;
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        //find LCA
        //find dist from LCA to each node
        Node* lca=findLca(root,a,b);
        //cout<<lca->data<<endl;
        int c1=0,c2=0;
        find(lca,a,c1);
        find(lca,b,c2);
        return c1+c2;
    }
};
