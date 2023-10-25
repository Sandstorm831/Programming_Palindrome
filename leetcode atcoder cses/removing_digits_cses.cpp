#include <bits/stdc++.h>
using namespace std;
vector<long long> extractor(long long n)
{
    vector<long long> v;
    long long x = n;
    while(x > 0)
    {
        v.push_back(x%10);
        x = x/10;
    }
    return v;
}
int main()
{
    long long n;cin>>n;
    vector<long long> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(long long i=1; i<=n; i++)
    {
        vector<long long> d = extractor(i);
        for(long long j=0; j<d.size();j++)
        {
            dp[i] = min(dp[i], 1+dp[i-d[j]]);
        }
    }
    cout<<dp[n]<<endl;
}