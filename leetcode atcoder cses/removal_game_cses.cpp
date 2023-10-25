#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;cin>>n;
    vector<long long> v(n); long long summ=0;
    for(long long i=0; i<n; i++) {cin>>v[i]; summ+=v[i];}
    vector<vector<long long>> dp(n, vector<long long> (n));
    for(long long i=0; i<n; i++)
    {
        for(long long j=i; j>=0; j--)
        {
            if(i == j) dp[i][j] = v[i];
            else
            {
                dp[i][j] = max(v[i]-dp[i-1][j], v[j]-dp[i][j+1]);
            }
        }
    }
    cout<<(summ + dp[n-1][0])/2<<endl;

    // For tabulation dp, as shown above, the question have to be think like player 1 is trying to maximize 
    // SCORE1-SCORE2 while player 2 is trying to minimize the same. 
    // For recursive approach, algorithm is straight forward.
}