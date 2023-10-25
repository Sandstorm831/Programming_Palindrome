#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp;
long long recursor(vector<long long>& a, long long b, long long e)
{
    if(b == e) return a[b];
    else if(b>e) return 0;
    else if(dp[b][e] != -1) return dp[b][e];
    return dp[b][e] =  max(a[b]+min(recursor(a,b+2, e), recursor(a, b+1,e-1)) , a[e]+min(recursor(a, b+1, e-1), recursor(a, b, e-2)));
}
int main()
{
    long long n;cin>>n;
    vector<long long> a(n);
    for(long long i=0; i<n; i++)cin>>a[i];
    long long summ = accumulate(a.begin(), a.end(), (long long)0);
    dp.clear(); dp.resize(n+1, vector<long long> (n+1, -1));
    cout<< -(summ-2*recursor(a, 0, a.size()-1));
}