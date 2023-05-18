#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0; i<cases; i++)
    {
        long long n,m;
        cin>>n>>m;
        long long summer=0;
        long long maxer= LLONG_MIN;
        long long miner = LLONG_MAX;
        for(long long j=0; j<n; j++)
        {
            long long x;
            cin>>x;
            summer+=x;
            maxer = max(maxer, x);
            miner = min(miner,x);
        }
        if(m<=n)
        {
            cout<<"NO"<<endl;
            continue;
        }
        summer = summer+maxer-miner+n;
        if(m>=summer) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

}