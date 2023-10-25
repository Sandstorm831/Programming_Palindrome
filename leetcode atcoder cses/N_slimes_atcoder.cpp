#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp;
long long recursor(vector<long long>& v, long long s, long long e, vector<long long>& c)
{
    if(e-s == 1) return v[s]+v[e];
    else if(s == e) return 0;
    else if(dp[s][e] != -1) return dp[s][e];
    else
    {
        long long counter=LLONG_MAX;
        for(long long i=s; i<e; i++)
        {
            long long summ;
            if(s == 0) summ = c[e];
            else summ = c[e]-c[s-1];
            counter = min(counter, recursor(v,s, i, c)+recursor(v, i+1,e, c)+summ);
        }
        return dp[s][e] = counter;
    }
}
int main()
{
    long long n;cin>>n;
    vector<long long> v(n), c(n,0);
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(long long i=0;i<n; i++){cin>>v[i]; pq.push(v[i]);}
    c[0] = v[0];
    for(long long i=1; i<n;i++) c[i] = c[i-1]+v[i];
    dp.clear(); dp.resize(n+1, vector<long long> (n+1, -1));
    cout<<recursor(v, 0, n-1, c);

}