#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    long long l, q;
    cin>>l>>q;
    vector<long long> d;
    for(long long j=0; j<l; j++)
    {
        long long a;
        cin>>a;
        d.push_back(a);
    }
    long long prev = d[0];
    long long ans=l*(l+1)/2;
    for(long long j=1; j<l; j++)
    {
        if(d[j]!=prev)
        {
            ans += j*(l-j);
            prev=d[j];
        }
    }
    for(long long k=0; k<q; k++)
    {
        long long x, y;
        cin>>x>>y;
        long long a = x-2;
        long long b = x;
        long long ls=0;
        long long rs = 0;
        if(a>=0 && d[a]!=d[x-1]) ls=1;
        if(b<l && d[x-1]!=d[b]) rs=1;
        d[x-1]=y;
        if(a>=0) 
        {
            if(ls==1 && d[a]==d[x-1])
            {
                ans-=(a+1)*(l-a-1);
                // cout<<"h";
            }
            else if(ls!=1 && d[a]!=d[x-1])
            {
                ans += (a+1)*(l-a-1);
                // cout<<"i";
            }

        }
        if(b<l)
        {
            if(rs==1 && d[b]==d[x-1])
            {
                ans-=x*(l-x);
                // cout<<"j";
            }
            else if(rs!=1 && d[b]!=d[x-1])
            {
                ans += x*(l-x);
                // cout<<"k";
            }
        }
        cout<<ans<<endl;
    }
}