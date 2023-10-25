#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp(1001, vector<int> (1<<11+1, -1));
const int mod = 1e9+7;
void generate_masks(int mask, int n, int index, int cur_mask, vector<int>& genmasks)
{
    if(index == n ) 
    {
        genmasks.push_back(cur_mask);
        return;
    }
    if(index == n-1)
    {
        if((mask & (1<<index)) == 0) generate_masks(mask, n, index+1, cur_mask+(1<<index), genmasks);
        else genmasks.push_back(cur_mask);
        return;
    }
    if((mask & (1<<index)) == 0)
    {
        generate_masks(mask, n, index+1, cur_mask+(1<<index), genmasks);
        if((mask & (1<<(index+1))) == 0)
        {
            generate_masks(mask, n, index+2, cur_mask, genmasks);
        }
    }
    else
    {
        generate_masks(mask, n, index+1, cur_mask, genmasks);
    }
}
int recursor(int n, int m, int index, int mask)
{
    if(index == m)
    {
        if(mask == 0) return 1;
        return 0;
    }
    else if(dp[index][mask] != -1) return dp[index][mask]%mod;
    vector<int> genmasks;
    generate_masks(mask, n, 0, 0, genmasks);
    int ans=0;
    for(int i=0; i<genmasks.size(); i++)
    {
        ans = (ans%mod + recursor(n,m , index+1, genmasks[i])%mod)%mod;
    }
    return dp[index][mask] = ans%mod;
}
int main()
{
    int n, m; cin>>n>>m;
    int inim = 0;
    int index = 0;
    cout<<recursor(n,m, index, inim);
}