#include <bits/stdc++.h>
using namespace std;
vector<vector<long double>> dp;
long double recursor(vector<long double>& v, long double n, long double index, long double h,long double t)
{   
    if(index == n)
    {
        if(h>t) return 1;
        else return 0; 
    }
    else if(dp[h][t] != -1) return dp[h][t];
    else
    {
        long double x = v[index]*recursor(v, n, index+1, h+1, t);
        long double y = (1-v[index])*recursor(v, n, index+1, h, t+1);
        return dp[h][t] = (long double)x+y;
    }
}
int main()
{
    long double n;cin>>n;
    vector<long double> v(n);
    for(long double i=0; i<n; i++) cin>>v[i];
    dp.clear(); dp.resize(n+1, vector<long double> (n+1, -1));
    cout<<setprecision(15)<<recursor(v, n, 0.0, 0.0, 0.0);
}