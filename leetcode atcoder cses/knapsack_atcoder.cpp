#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp;
long long recursor(vector<pair<long long,long long>>& vp, long long n, long long w, long long index)
{
    if(index >= vp.size()) return 0;
    else if(w == 0) return 0;
    else if(dp[index][w] != -1) return dp[index][w];
    else
    {
        if(vp[index].first <= w)
        {
            return dp[index][w] = max(vp[index].second+ recursor(vp, n, w-vp[index].first, index+1), recursor(vp, n, w, index+1));
        }
        else return dp[index][w] = recursor(vp, n, w, index+1);
    }
}
int main()
{
    long long n, w;cin>>n>>w;
    vector<pair<long long,long long>> vp(n);
    for(long long i=0; i<n; i++) cin>>vp[i].first>>vp[i].second;
    dp.clear(); dp.resize(n+1, vector<long long> (w+1, -1));
    cout<<recursor(vp, n, w, 0)<<endl;
}