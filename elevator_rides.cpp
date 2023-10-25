#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x; cin>>n>>x;
    vector<int> weight(n);
    vector<pair<int,int>> dp(1<<n);
    for(int i=0; i<n; i++) cin>>weight[i];
    dp[0].first = 1;
    dp[0].second = 0;
    for (int s = 1; s < (1<<n); s++)
    {
        // initial value: n+1 rides are needed
        dp[s].first = n+1; dp[s].second = 0;
        for(int i=0; i<n; i++)
        {
            if(s&(1<<i))
            {
                pair<int,int> temp = dp[s^(1<<i)];
                if(temp.second + weight[i] <= x) temp.second += weight[i];
                else 
                {
                    temp.first++;
                    temp.second = weight[i];
                }
                dp[s] = min(dp[s], temp);
            }
        }
    }
    cout<<dp.back().first<<endl;
}