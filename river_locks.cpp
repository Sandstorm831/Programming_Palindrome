#include <bits/stdc++.h>
using namespace std;
long long miner(vector<long long>& v, long long lock)
{
    long long ini = v[1];
    long long over = 0;
    for(long long i=2; i<=lock; i++)
    {
        if(ini + over >= v[i])
        {
            over = over+ini-v[i];
        }
        else
        {
            long long x = ceil(double(double(v[i]-ini-over)/double(i)));
            over = x*(i)+ini+over-v[i];
            ini = x+ini;
        }
    }
    return ini;
}
long long main()
{
    long long locks;
    cin>>locks;
    vector<long long> v(locks+1);
    long long cap=0;
    for(long long i=1; i<=locks; i++)
    {
        cin>>v[i];
        cap+=v[i];
    }
    long long q;
    cin>>q;
    vector<long long> qrs(q+1);
    for(long long i=1; i<=q; i++)
    {
        cin>>qrs[i];
    }
    long long minn = miner(v,locks);
    for(long long i=1; i<=q; i++)
    {
        if(qrs[i]<minn) cout<<-1<<endl;
        else
        {
            long long x = ceil(double(double(cap)/double(qrs[i])));
            if(x<=locks) cout<<x<<endl;
            else cout<<-1<<endl;
        }
    }
}