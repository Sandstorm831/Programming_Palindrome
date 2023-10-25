#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp;
int main()
{
    const long long mod = 1e9+7;
    long long n;cin>>n;
    long long x = n*(n+1)/2;
    if(x%2 == 1)
    {
        cout<<0<<endl;return 0;
    }
    dp.clear(); dp.resize(n+1, vector<long long> (x+1, 0));
    dp[0][0]=1;
    for(long long j=0; j<=(x/2); j++)
    {
        for(long long i=1; i<n; i++)
        {
            if(i<=j) (dp[i][j] = dp[i-1][j] + dp[i-1][j-i])%=mod;
            else (dp[i][j] = dp[i-1][j])%=mod;
        }
    }
    cout<<dp[n-1][x/2];
}