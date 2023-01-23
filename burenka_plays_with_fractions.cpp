#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b)
{
    if(b==0) return a;
    else return gcd(b, a%b);
}
long long lcm(long long a, long long b)
{
    return (a*b)/gcd(a,b);
}
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0;i<cases;i++)
    {
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        long long x = b*c;
        long long y = d*a;
        long long gc = gcd(x,y);
        if(x == y) cout<<0<<endl;
        else if(gc == x || gc == y) cout<<1<<endl;
        else cout<<2<<endl;
    }
}