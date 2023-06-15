#include<bits/stdc++.h>
using namespace std;
long long int factorial(long long x)
{
    if(x == 1 || x == 0) return 1;
    else return x*factorial(x-1);
}
int main()
{
    long long mult = sqrt(8)/9801;
    string sum="";
    int n=0;
    long long thrit = pow(396,4);
    while(true)
    {
        long long temp = mult*((factorial(4*n)/(pow(factorial(n),4)*(pow(thrit,n))))*(1103+26390*n));
        sum += to_string(temp);
        if(sum.length() >= 2) break;
    }
    cout<<sum;
}