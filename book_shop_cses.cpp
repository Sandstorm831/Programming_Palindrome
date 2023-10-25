#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;cin>>n>>x;
    vector<int> price(n), pages(n);
    for(int i=0; i<n; i++) cin>>price[i];
    for(int i=0; i<n; i++) cin>>pages[i];
    vector<vector<int>> dp(n+1, vector<int> (x+1, 0));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=x; j++)
        {
            if(price[i-1] <= j) dp[i][j] = max(pages[i-1] + dp[i-1][j-price[i-1]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][x]<<endl;
}