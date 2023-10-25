#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;cin>>n;
    const long long mod=1e9+7;
    vector<vector<char>> graph(n, vector<char> (n));
    for(long long i=0; i<n; i++) for(long long j=0; j<n; j++) cin>>graph[i][j];
    vector<vector<long long>> dp(n+1, vector<long long> (n+1, 0));
    for(long long i=n; i>0; i--) 
    {
        if(graph[i-1][n-1] == '*') break;
        else dp[i][n] = 1;
    }
    for(long long i=n; i>0; i--) 
    {
        if(graph[n-1][i-1] == '*') break;
        else dp[n][i] = 1;
    }
    for(long long j=n-1; j>0; j--)
    {
        for(long long k=n-1; k>0; k--)
        {
            if(graph[j-1][k-1] == '*') dp[j][k] = 0;
            else (dp[j][k] += dp[j+1][k]+dp[j][k+1])%=mod;
        }
    }
    cout<<dp[1][1]<<endl;
}