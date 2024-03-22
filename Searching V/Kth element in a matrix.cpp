//https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1




int count(int mat[MAX][MAX],int n,int i,int x)
{
    int b=0,e=n-1;
    while(b<=e){
        int m=(b+e)/2;
        if(mat[i][m]<=x){
            b=m+1;
            ans=m+1;
        }
        else{
            e=m-1;
        }
    }
    return b;
}
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  int l=INT_MAX,h=0,ans;
  for(int i=0;i<n;i++){
      l=min(l,mat[i][0]);
      h=max(h,mat[i][n-1]);
  }
  while(l<=h)
  {
      int m=(l+h)/2;
      int c=0;
      for(int i=0;i<n;i++) c+=count(mat,n,i,m);
      if(c<k){
          l=m+1;
      }
      else{
          h=m-1;
      }
  }
  return l;
}
