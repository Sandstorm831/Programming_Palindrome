#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
vector<int> dp(1e6+5, -1);
int recursor(int n)
{
    if(n == 0) return 1;
    else if(n < 0) return 0;
    else if(dp[n] != -1) return dp[n];
    else 
    {
        int counter=0;
        for(int i=1; i<=6; i++)
        {
            counter=(counter%mod + recursor(n-i)%mod)%mod;
        }
        return dp[n] = counter%mod;
    }
}
int main()
{
    int n;cin>>n;
    cout<<recursor(n);
}