#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;
int main()
{
    long long n, k;cin>>n>>k;
    vector<long long> v(n);
    for(long long i=0;i<n; i++)cin>>v[i];
    vector<vector<long long>> dp(n, vector<long long> (k+1,0));
    for(long long i=0; i<n; i++)
    {
        vector<long long> pr(k+1, 0);
        if(i>0)
        {
            pr[0] = dp[i-1][0];
            for(long long j=1;j<=k; j++) pr[j] = (pr[j-1]%mod+dp[i-1][j]%mod)%mod;
        }
        for(long long j=0; j<=k;j++)
        {
            if(i == 0 && j<=v[0]) dp[i][j] = 1;
            else if(j == 0) dp[i][j] = 1;
            else
            {
                if(v[i]<j) dp[i][j] = (pr[j] - pr[j-v[i]-1]+mod)%mod;
                else dp[i][j] = pr[j]%mod;
            }
        }
    }
    cout<<dp[n-1][k]<<endl;
}