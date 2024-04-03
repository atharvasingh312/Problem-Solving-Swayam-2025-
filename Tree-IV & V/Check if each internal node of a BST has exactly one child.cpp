//https://www.geeksforgeeks.org/check-if-each-internal-node-of-a-bst-has-exactly-one-child/

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &preorder){
    for(int i=1;i<preorder.size();i++)
    {
        //current node for which i check is i-1
        if(preorder[i-1]>preorder[i] && preorder[i-1]<preorder[preorder.size()-1]
        || preorder[i-1]<preorder[i] && preorder[i-1]>preorder[preorder.size()-1]) return false;
    }
    return true;
}
int main()
{
    //given preorder find if all have only one child
    vector<int> preorder={1,2,3,6,7,5};
    //if both left and right exist then last succesor greater than node and immediate succesor smaller than node 
    if(check(preorder)){
        cout<<"All have one decendant"<<endl;
    }
    else{
        cout<<"All dont have one decendant"<<endl;
    }
    return 0;
}
