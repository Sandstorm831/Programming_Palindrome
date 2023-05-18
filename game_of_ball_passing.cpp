#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0; i<cases;i++)
    {
        long long n;
        cin>>n;
        vector<long long> v;
        long long summer=0;
        for(long long j=0;j<n; j++)
        {
            long long x;
            cin>>x;
            summer+=x;
            v.push_back(x);
        }
        if(summer == 0)
        {
            cout<<0<<endl;
            continue;
        }
        sort(v.begin(), v.end());
        long long maxy = v[n-1];
        long long maxer = v[n-2];
        if(summer-maxy <= maxy) cout<<max(2*maxy-summer, (long long)1)<<endl;
        else cout<<1<<endl;
    }
}