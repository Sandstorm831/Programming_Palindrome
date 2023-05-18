#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0; i<cases; i++)
    {
        long long n;
        cin>>n;
        vector<long long> v;
        long long minn = LLONG_MAX;
        for(long long j=0; j<n; j++)
        {
            long long x;
            cin>>x;
            x = log2(float(x&~(x-1)));
            v.push_back(x);
            minn = min(minn, x);
        }
        long long summer=0;
        long long count=0;
        for(long long j=0; j<v.size(); j++)
        {
            summer+=v[j];
            if(v[j]==minn) count++;
        }
        long long ll;
        if(minn == 0)
        {
            ll = n-count;
        }
        else
        {
            ll = n-1+minn;
        }
        cout<<min(summer, ll)<<endl;
    }
}