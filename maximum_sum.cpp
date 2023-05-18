#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0; i<cases; i++)
    {
        long long n, m;
        cin>>n>>m;
        vector<long long> v;
        long long summ=0;
        long long summer=0;
        for(long long j=0; j<n; j++)
        {
            long long x;
            cin>>x;
            v.push_back(x);
            summer+=x;
        }
        sort(v.begin(), v.end());
        for(long long j=0; j<2*m; j++)
        {
            summ+=v[j];
        }
        // cout<<summ<<endl;
        long long k=2*m-1;
        long long l=n-1;
        long long orig = LLONG_MAX;
        while(k>=0 && l>=0)
        {
            orig = min(orig, summ);
            summ += v[l]-v[k]-v[k-1];
            k--;
            k--;
            l--;
        }
        orig = min(orig, summ);
        cout<<summer-orig<<endl;
    }
}