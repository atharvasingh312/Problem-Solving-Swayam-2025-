//https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

int ans=-1;
int findCeil(Node* root, int input) {
    //probable ans on moving left
    if(!root) return ans;
    else if(root->data>=input){
        ans=root->data;
        return findCeil(root->left,input);
    }
    else return findCeil(root->right,input);
}
