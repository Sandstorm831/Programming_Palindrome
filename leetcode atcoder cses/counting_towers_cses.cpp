#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cases;cin>>cases;
    const long long mod = 1e9+7;
    long long n=1e6+3;
    vector<vector<long long>> dp(n+1, vector<long long> (3, 0));
    dp[1][1] = 1, dp[1][2] = 1;
    for(long long i=2; i<=n; i++)
    {
        (dp[i][1] = 4*dp[i-1][1] + dp[i-1][2])%=mod;
        (dp[i][2] = dp[i-1][1] + 2*dp[i-1][2])%=mod;
    }
    while(cases--)
    {
        int nn;cin>>nn;
        cout<<(1ll*dp[nn][1]+1ll*dp[nn][2])%mod<<endl;
    }
}
// for understanding - https://github.com/mrsac7/CSES-Solutions/blob/master/src/2413%20-%20Counting%20Towers.cpp