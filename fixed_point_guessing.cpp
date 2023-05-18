#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);cout<<setprecision(25);
int main()
{
    IOS;
    long long cases;
    cin>>cases;
    for(long long i=0; i<cases; i++)
    {
        unordered_set<long long> sety;
        long long n;
        cin>>n;
        if(n==-1) break;
        long long a=1;
        long long f = n;
        long long b = (a+f)/2;
        long long l = 0;
        while(l!=1)
        {
            cout<<"? "<<a<<" "<<b<<endl;
            // fflush(stdout);
            long long c=0;
            sety.clear();
            for(long long j=0; j<b-a+1; j++)
            {
                long long x;
                cin>>x;
                if(x>=a && x<=b)
                {
                    c++;
                    sety.insert(x);
                }
            }
            l=c;
            if(l==1)
            {
                cout<<"! "<<*sety.begin()<<endl;
                break;
                // fflush(stdout);
            }
            else
            {
                if(l%2==0)
                {
                    a=b+1;
                    b=(a+f)/2;
                }
                else
                {
                    f=b;
                    b=(a+f)/2;
                }
            }
        }
    }
}