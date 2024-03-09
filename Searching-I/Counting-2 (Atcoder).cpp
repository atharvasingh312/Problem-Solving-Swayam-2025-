https://atcoder.jp/contests/abc231/submissions/51001306


/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std; 

int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    for(int i=0;i<q;i++)
    {
        int x;
    cin>>x;
    int b=0,e=n-1,ans=n;
    while(b<=e)
    {
        int m=(b+e)/2;
        if(arr[m]>=x){
            ans=m;
            e=m-1;
        }
        else b=m+1;
    }
    cout<<n-ans<<endl;
    }
    return 0;
}
