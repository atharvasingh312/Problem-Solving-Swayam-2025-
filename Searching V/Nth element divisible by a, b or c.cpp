#include <bits/stdc++.h>
using namespace std;

int count(int m,int a,int b,int c){
    int x=min({a,b,c});
    int count=0;
    for(int k=x;k<=m;k++){
        if(k%a==0 || k%b==0 || k%c==0) count++;
    }
    return count;
}
int main()
{
    int a=2,b=4,c=7;
    int n=10;//find tenth divisble by a,b or c
    int l=min({a,b,c});
    int h=max({a,b,c})*n;
    while(l<=h)
    {
        int m=(l+h)/2;
        if(count(m,a,b,c)==n){
            cout<<m;
            break;
        }
        else if(count(m,a,b,c)<n){
            l=m+1;
        }
        else h=m-1;
    }
    return 0;
}
