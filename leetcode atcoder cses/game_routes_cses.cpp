#include <bits/stdc++.h>
using namespace std;
vector<long long> dp;
const long long mod=1e9+7;
long long recursor(vector<vector<long long>>& alter, long long node)
{
    if(node == 1) return 1;
    else if(dp[node] != -1) return dp[node];
    long long counter=0;
    for(long long i=0; i<alter[node].size(); i++)
    {
        counter = (counter + recursor(alter, alter[node][i]))%mod;
    }
    return dp[node] = counter%mod;
}
int main() 
{
    long long n,m;cin>>n>>m;
    vector<vector<long long>> graph(n+1, vector<long long> ()), alter(n+1, vector<long long> ());
    for(long long i=0; i<m; i++) 
    {
        long long x,y;cin>>x>>y;
        graph[x].push_back(y);
        alter[y].push_back(x);
    }
    dp.clear(); dp.resize(n+1, -1);
    cout<<recursor(alter, n);
}