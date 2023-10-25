#include <bits/stdc++.h>
using namespace std;

int main()
{
    const long long mod = 1e9+7;
    long long n, m; cin>>n>>m;
    long long x0; cin>>x0;
    vector<vector<long long>> dp(n, vector<long long> (m+1, 0));
    if(x0 == 0) fill(dp[0].begin(), dp[0].end(), 1);
    else dp[0][x0] = 1;
    for(long long i=1; i<n; i++)
    {
        long long xx; cin>>xx;
        if(xx == 0)
        {
            for(long long j=1; j<=m; j++)
            {
                for(long long k=j-1; k<=j+1; k++)
                {
                    if(k>=1&&k<=m) (dp[i][j]+=dp[i-1][k])%=mod;
                }
            }
        }
        else
        {
            for(long long k=xx-1; k<=xx+1; k++)
            {
                if(k>=1 && k<=m) (dp[i][xx]+=dp[i-1][k])%mod;
            }
        }
    }
    long long ans = 0;
    for(long long i=1; i<=m; i++)
    {
        (ans+=dp[n-1][i])%=mod;
    }
    cout<<ans<<endl;
}