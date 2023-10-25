#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cases;cin>>cases;
    while(cases--)
    {
        long long n,k,a,b;cin>>n>>k>>a>>b;
        long long x = n/k;
        long long y = n%k;
        if(b >= x && a >= y) cout<<0<<endl;
        else
        {
            long long x = n%k;
            if(a >=x)
            {
                a -= x;
                n-=x;
                b += a/k;
                n -= b*k;
                n = max(0ll,n);
                cout<<n/k<<endl;
            }
            else
            {
                long long rem = x - a;
                n -= x;
                n -= b*k;
                n = max(0ll,n);
                cout<<(n/k) + rem <<endl;   
            }
        }
    }
}