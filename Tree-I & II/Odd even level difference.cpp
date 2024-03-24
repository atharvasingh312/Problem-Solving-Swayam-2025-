//https://www.geeksforgeeks.org/problems/odd-even-level-difference/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution{
  public:
    /*You are required to complete this function*/
    int getLevelDiff(Node *root)
    {
       //Your code here
       queue<Node*> q;
       int even=0,odd=0;
       q.push(root);
       int l=0;
       while(!q.empty())
       {
           int sz=q.size(),sum=0;
           for(int k=0;k<sz;k++)
           {
               Node* f=q.front();
               q.pop();
               sum+=f->data;
               if(f->left)
               {
                   q.push(f->left);
               }
               if(f->right)
               {
                   q.push(f->right);
               }
           }
           if(l==0){
               even+=sum;
           }
           else{
               odd+=sum;
           }
           l=(l+1)%2;
       }
       return even-odd;
    }
};
