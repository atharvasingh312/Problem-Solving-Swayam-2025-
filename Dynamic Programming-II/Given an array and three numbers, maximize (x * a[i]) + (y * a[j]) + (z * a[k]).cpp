//https://www.geeksforgeeks.org/given-array-three-numbers-maximize-x-ai-y-aj-z-ak/

#include <bits/stdc++.h>
using namespace std;
#define int long long


int solve(int x,int y,int z,int i,int p,vector<int> &arr){
    if(i==arr.size()) {
        if(p==3) return 0;
        else     return INT_MIN;
    }
    int pick=0;
    if(p==0) pick=(x*arr[i])+solve(x,y,z,i+1,p+1,arr);
    else if(p==1) pick=(y*arr[i])+solve(x,y,z,i+1,p+1,arr);
    else if(p==2) pick=(z*arr[i])+solve(x,y,z,i+1,p+1,arr);
    return max(solve(x,y,x,i+1,p,arr),pick);
    
}
signed main()
{
    vector<int> arr={-1, -2, -3, -4, -5};
    int x=1,y=-2,z=-3;
    cout<<solve(x,y,z,0,0,arr)<<endl;
    return 0;
}
