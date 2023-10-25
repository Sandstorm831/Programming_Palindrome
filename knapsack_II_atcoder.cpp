#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp;
long long recursor(vector<long long>& wt, vector<long long>& val, long long index, long long valv)
{
    if(valv == 0) return 0;
    else if(index >= val.size()) return 1e15;
    else if(dp[index][valv] != -1) return dp[index][valv];
    else
    {
        long long x = recursor(wt,  val, index+1, valv);
        if(valv-val[index] >= 0) x = min(x, wt[index]+recursor(wt,val, index+1, valv-val[index]));
        return dp[index][valv] = x;
    }
}
int main()
{
    long long n, w; cin>>n>>w;
    vector<long long> val(n), wt(n);
    for(long long i=0; i<n; i++) cin>>wt[i]>>val[i];
    long long acc = accumulate(val.begin(), val.end(), (long long)0);
    dp.clear();dp.resize(n+1, vector<long long> (acc+1, -1));
    for(long long i = acc; i>=0; i--)
    {
        if(recursor(wt, val, 0, i) <= w) {cout<<i<<endl;break;}
    }
}