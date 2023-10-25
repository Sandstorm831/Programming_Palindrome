#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    const long long mod = 1e9+7;
    long long n, x; cin>>n>>x;
    vector<long long> v(n);
    for(long long i=0; i<n; i++) cin>>v[i];  
    vector<long long> dp(x+1, 0);
    dp[0] = 1;
    long long nn = v.size();
    sort(v.begin(), v.end());
    reverse(v.begin(),v.end());
    for(long long i=1; i<= x; i++)
    {
        for(long long j=0; j<nn; j++)
        {
            if(v[j] <= i) (dp[i] += dp[i-v[j]])%=mod;
        }
    }
    cout<<dp[x]<<endl;
}