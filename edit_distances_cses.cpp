#include <bits/stdc++.h>
using namespace std;
int main()
{
    string n, m;
    cin>>n>>m;
    vector<vector<int>> dp(n.length()+1, vector<int> (m.length()+1, 0));
    for(int i=0; i<=n.length(); i++) dp[i][0] = i;
    for(int i=0; i<=m.length(); i++) dp[0][i] = i;
    for(int i=1;i<=n.length(); i++)
    {
        for(int j=1; j<=m.length();j++)
        {
            if(n[i-1] == m[j-1]) dp[i][j] = dp[i-1][j-1];
            else
            {
                dp[i][j] = min({1+dp[i-1][j], 1+dp[i][j-1], 1+dp[i-1][j-1]});
            }
        }
    }
    cout<<dp[n.length()][m.length()];

}