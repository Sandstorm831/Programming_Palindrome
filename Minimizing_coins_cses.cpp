#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,x;cin>>n>>x;
    vector<long long> v(n);
    for(long long i=0; i<n;i++) cin>>v[i];
    sort(v.begin(), v.end());
    vector<long long> dp(x+1, INT_MAX);
    dp[0] = 0;
    for(int i=1; i<=x; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i-v[j]>=0) dp[i] = min(dp[i], dp[i-v[j]]+1);
        }
    }
    cout<<(dp[x] == INT_MAX ? -1:dp[x])<<endl;
}