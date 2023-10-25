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
    for(long long i=0; i<nn; i++)
    {
        for(long long j=1; j<=x; j++)
        {
            if(v[i] <= j) (dp[j] += dp[j-v[i]])%=mod;
        }
    }
    cout<<dp[x]<<endl;
}