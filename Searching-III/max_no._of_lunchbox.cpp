/*Deepthi loves cruises. She is going to visit the Caribbean on a Cruise. So, she thought of providing everyone who is traveling with her with lunch as well. Each food item is denoted by an integer ID. A lunch box contains exactly A food items. She has a list of food items with her denoted by an integer array B. She asked you to tell her the maximum number of lunchboxes she can prepare.

Note:
A lunch box can contain multiple same kinds of food items but the content of each lunch box should be the same.
Example Input
Input 1:
A = 3, B = [1, 2, 3, 2, 6, 1, 3]
Input 2:
A = 4, B = [1, 3, 1, 3, 10, 3, 6, 6, 13]
Example Output
Output 1:
2
Output 2:
1
Example Explanation
Explanation 1:
She can choose the content to be [1, 2, 3] and prepare 2 luchboxes
Explanation 2:
She can choose the content to be [1, 3, 3, 3]
*/




#include <bits/stdc++.h>
using namespace std;


bool check(int l,int a,unordered_map<int,int> &mp){
    //l is the luchboxes and a is item per lunchbox
    int n=0;//max no. of item per box
    for(auto x:mp)
    {
        n+=(x.second/l);
    }
    if(n>=a) return true;
    else     return false;
}
int solve(vector<int> &arr,int a)
{
    unordered_map<int,int> mp;
    int l=0,h=arr.size()/a;//max luch box you can pack
    for(auto x:arr) mp[x]++;
    int ans=0;
    while(l<=h)
    {
        int m=(l+h)/2;
        if(check(m,a,mp)){//agar x lunch box pack kar lu to use se kam obviously kar lunga
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
    int a,n;//n is the isze of array
    cin>>a>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<solve(arr,a);
    return 0;
}
