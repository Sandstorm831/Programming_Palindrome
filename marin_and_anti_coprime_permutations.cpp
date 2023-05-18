#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        long long n;
        cin>>n;
        if(n%2==1) 
        {
            cout<<0<<endl;
            continue;
        }
        long long mod = 998244353;
        long long x = 1;
        long long counter = n/2;
        while(counter>0)
        {
            x = (x%mod * (counter)%mod)%mod;
            counter--;
        }
        x = ((x%mod) * (x%mod))%mod;
        cout<<x<<endl;

    }
}