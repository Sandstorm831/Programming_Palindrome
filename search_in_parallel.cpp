#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0; i<cases; i++)
    {
        long long n,s,l;
        cin>>n>>s>>l;
        vector<pair<long long, long long>> v;
        for(long long j=1; j<=n; j++)
        {
            long long x;
            cin>>x;
            v.push_back(make_pair(x,j));
        }
        sort(v.rbegin(), v.rend());
        vector<long long> a;
        vector<long long> b;
        for(long long j=0; j<v.size(); j++)
        {
            long long ta = (a.size()+1)*s;
            long long tb = (b.size()+1)*l;
            if(ta<tb) a.push_back(v[j].second);
            else b.push_back(v[j].second);
        }
        cout<<a.size()<<" ";
        for(long long j=0; j<a.size(); j++)
        {
            cout<<a[j]<<" ";
        }
        cout<<endl<<b.size()<<" ";
        for(long long j=0; j<b.size(); j++)
        {
            cout<<b[j]<<" ";
        }
        cout<<endl;
    }
}