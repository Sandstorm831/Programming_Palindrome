#include <bits/stdc++.h>
using namespace std;
long long msb(long long x)
{
    long long b = __builtin_clz(x);
    return (31-b);
}
int main()
{
    long long  mod = 1e9+7;
    long long n, p;
    cin>>n>>p;
    vector<long long> v;
    for(long long j=0;j<n;j++)
    {
        long long x;
        cin>>x;
        if(msb(x) >= p) continue;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    set<long long> useful;
    for(long long j=0; j<v.size(); j++)
    {
        // cout<<v[j]<<" ";
        long long a = v[j];
        bool flag=false;
        while(a>0)
        {
            if(useful.count(a)) flag=true;
            if(a&1) a>>=1;
            else if(a&3) break;
            else a>>=2;
        }
        if(!flag) useful.insert(v[j]);
    }
    long long summ=0;
    vector<long long> d;
    // for(long long j=0; j<v.size(); j++) cout<<v[j]<<" ";
    for(auto itr=useful.begin(); itr!=useful.end(); itr++)
    {
        d.push_back(*itr);
    }
    // for(long long j=0;j<d.size(); j++) cout<<d[j]<<" ";
    vector<long long> dp(p+1, 0);
    for(long long j=0; j<d.size(); j++)
    {
        // cout<<d[j]<<endl;
        long long pd = msb(d[j]);
        dp[pd]++;
    }
    for(long long j=1; j<dp.size(); j++)
    {
        if(j==1) dp[j] = (dp[j]%mod + dp[j-1]%mod)%mod;
        else dp[j] = (dp[j]%mod + (dp[j-1]%mod + dp[j-2]%mod)%mod)%mod;
    }
    // for(long long j=0; j<dp.size();j++) cout<<dp[j]<<" ";
    for(long long j=0; j<p; j++)
    {
        summ = (summ%mod + dp[j]%mod)%mod;
    }
    cout<<summ<<endl;
}