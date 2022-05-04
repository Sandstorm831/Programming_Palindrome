//Problem Link - https://www.interviewbit.com/problems/trailing-zeroes/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int A = 423000; // This has to be assumed;
    int n=0;
    int L = A&1;

    while(L==0)
    {
        n=n+1;
        A = A>>1;
        L = A&1;
    }
    cout<<n;
}