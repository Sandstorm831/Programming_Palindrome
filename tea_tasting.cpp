#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n; cin>>n;
        vector<long long> a, b, c; 
        b.push_back(0ll);
        for(int j=0; j<n; j++)
        {
            long long x;cin>>x;
            a.push_back(x);
        }
        long long summ=0;
        for(int j=0; j<n; j++)
        {
            long long x; cin>>x;
            c.push_back(x);
            summ+=x;
            b.push_back(summ);
        }
        vector<long long> cnt(n+1,0);
        vector<long long> adt(n+1,0);
        for(int j=0; j<a.size(); j++)
        {
            long long x = b[j]+a[j];
            int index = upper_bound(b.begin(), b.end(), x)-b.begin()-1;
            cnt[j] += 1;
            cnt[index] += -1;
            adt[index] += a[j]+b[j]-b[index];
        }
        summ=0;
        for(int j=0; j<n; j++)
        {
            cout<<adt[j]+cnt[j]*c[j]<<" ";
            cnt[j+1]+=cnt[j];
        }
        cout<<endl;
    }
}