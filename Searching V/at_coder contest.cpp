#include<bits/stdc++.h> 
using namespace std;
#define int long long


int count(vector<int> &b,int t)
{
    int l=0,r=b.size()-1,ans=0;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(t>=b[m]){
            l=m+1;
            ans=l;
        }
        else r=m-1;
    }
    return l;
}
signed main(){
  int n,m,t;
  cin>>n>>m>>t;
  vector<int> a(n,0),b(m,0);
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(i>0)
    a[i]+=a[i-1];
  }
  for(int i=0;i<m;i++){
    cin>>b[i];
    if(i>0)
    b[i]+=b[i-1];
  }
  int ans=0;
  for(int i=0;i<a.size();i++){
      int d=t-a[i];
      if(d>=0){
          ans=max(i+1+count(b,d),ans);
      }
  }
  cout<<ans<<endl;
  return 0;
}
