// Problem Link - https://www.interviewbit.com/problems/implement-power-function/
#include <bits/stdc++.h>
using namespace std;
int helper(long long int x,long long int n,long long int d)
{
    if(d == 1) return 0;
    long long int ans = 1, y = x%d;
    while(n>0)
    {
        if(n&1) ans = (ans*y)%d;
        y = (y*y)%d;
        if(y<0) y+=d;
        n = n/2;
    }
    if(ans<0) return (d+ans)%d;
    else return ans;
    
}
int main()
{
    long long int x =   71045970;
    long long int n =   41535484;
    long long int d =   64735492;
    cout<<helper(x,n,d);
}
