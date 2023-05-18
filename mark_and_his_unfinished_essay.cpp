#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0; i<cases; i++)
    {
        long long n, c, q;
        cin>>n>>c>>q;
        vector<char> s;
        for(long long j=0; j<n;j++)
        {
            char d;
            cin>>d;
            s.push_back(d);
        }
        long long l=n;
        vector<long long> v(c+1);
        vector<long long> p(c+1);
        v[0]=0;
        p[0]=0;
        for(long long j=1; j<=c; j++)
        {
            long long x,y;
            cin>>x>>y;
            v[j] = x-l-1;
            p[j] = l;
            l += y-x+1;
        }
        for(long long j=0; j<q; j++)
        {
            long long x;
            cin>>x;
            long long index = x;
            while(index>n)
            {
                long long sub = lower_bound(p.begin(), p.end(), index)-p.begin();
                index += v[sub-1];
            }
            cout<<s[index-1]<<endl;
        }
    }
}