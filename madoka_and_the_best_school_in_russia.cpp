#include <bits/stdc++.h>
using namespace std;
set<long long> isprime(long long x)
{
    set<long long> v;
    for(long long j=2; j*j<=x; j++)
    {
        if(x%j == 0) v.insert(j);
    }
    return v;
}
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0; i<cases;i++)
    {
        long long x,d, orig;
        cin>>x>>d;
        orig=x;
        long long a=0;
        while(x%d==0)
        {
            x/=d;
            a++;
        }
        orig /= x;
        if(a == 1){
            cout<<"NO"<<endl;
            continue;
        }
        if(isprime(x).size() != 0)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        if(isprime(d).size() == 0)
        {
            cout<<"No"<<endl;
            continue;
        }
        if(isprime(d).size() >=2)
        {
            if(a==2) cout<<"No"<<endl;
            else if(a>2) cout<<"Yes"<<endl;
            continue;
        }
        if(isprime(d).size() == 1)
        {
            if(a == 2) cout<<"No"<<endl;
            if(a==3)
            {
                int p = *(isprime(d).begin());
                if(d == p*p)
                {
                    if(x == p) cout<<"No"<<endl;
                    else cout<<"Yes"<<endl;
                }
                else cout<<"Yes"<<endl;
            }
            if(a>3) cout<<"Yes"<<endl;
            continue;
        }
    }
}