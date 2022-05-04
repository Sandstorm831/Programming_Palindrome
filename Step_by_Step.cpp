// Problem Link - https://www.interviewbit.com/problems/step-by-step/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long int A = -34556; // This value has to be assumed
    long int a = abs(A);
    long double k = sqrt(1+8*a)-1;
    int n = (k)/2;
    if(floor(k) != k){
        n +=1;
        int sum = n*(n+1)/2;
        if ((sum-a)%2 == 0)
        {   
            cout<<(n);
        }
        else if ((sum+n+1-a)%2 == 0)
        {
            cout<<(n+1);
        }
        else
        {
            cout<<(n+2);
        }
    }
    else
    {
        cout<<n;
    }
}