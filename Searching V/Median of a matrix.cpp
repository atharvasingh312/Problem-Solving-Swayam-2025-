//https://www.interviewbit.com/problems/matrix-median/


int count(int x,vector<vector<int>> &A,int ind,int n12){
    int b=0,e=n12-1,ans=0;
    while(b<=e){
        int m=(b+e)/2;
        if(A[ind][m]<=x){
            ans=m;
            b=m+1;
        }
        else{
            e=m-1;
        }    
    }
    return b; 
}
int Solution::findMedian(vector<vector<int> > &A) {
    int n11=A.size(),n12=A[0].size();
    int l=INT_MAX,h=0;
    for(int i=0;i<n11;i++)
    {
        l=min(l,A[i][0]);
        h=max(h,A[i][n12-1]);
    }
    int sz=(n11*n12)/2;
    int ans=-1;
    while(l<=h){
        int m=(l+h)/2;
        int c=0;
        for(int k=0;k<n11;k++) c+=count(m,A,k,n12);//less than equal to
        if(c<=sz)
        {
            l=m+1;
        }
        else      h=m-1;
        
    }
    return l;
}
