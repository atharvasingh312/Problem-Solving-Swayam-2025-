/*You have given an array A having N elements and an integer S. You have to find a maximum number X such that the sum of all its subarrays of size X is less than or equal to S.
Example Input:  
    A = [1, 3, 4, 2]  
    S = 7  
Example Output:  
    2  
Explanation:  
    All subarrays of size 2 have the sum less than 7.  
    Subarays are :  
    1. [1, 3]  
    2. [3, 4]  
    3. [4, 2]
*/



#include <bits/stdc++.h>
using namespace std;


bool check(int m,vector<int> &arr,int s){
    int b=0,e=m;
    int sum=0;
    for(int k=0;k<e;k++) sum+=arr[k];
    int mx=sum;
    while(e<arr.size())
    {
        sum=sum-arr[b]+arr[e];//m size ke sab subarray less than or equal to s
        e++;
        b++;
        mx=max(sum,mx);
    }
    if(mx>s) return false;
    else     return true;
}
int solve(vector<int> &arr,int s)
{
    int l=1,h=arr.size();
    int ans=-1;
    while(l<=h)
    {
        int m=(l+h)/2;
        if(check(m,arr,s)){
            ans=m;
            l=m+1;
        }
        else{
            h=m-1;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr;
    arr={1,3,4,2};
    int s=7;
    cout<<solve(arr,s);
    return 0;
}
