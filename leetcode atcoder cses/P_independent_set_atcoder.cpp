#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp;
const long long mod = 1e9+7;
long long recursor(vector<vector<long long>>& graph, long long index, long long col, long long par)
{
    if(dp[index][col] != -1) return dp[index][col]%mod;
    long long counter=1;
    for(long long i=0; i<graph[index].size(); i++)
    {
        long long temp=0;
        if(graph[index][i] == par) continue;
        if(col == 0)
        {
            temp = (temp%mod + recursor(graph, graph[index][i], col, index)%mod)%mod;
            temp = (temp%mod + recursor(graph, graph[index][i], 1, index)%mod)%mod;
        }
        else
        {
            temp = (temp%mod + recursor(graph, graph[index][i], 0, index)%mod)%mod;
        }
        counter = ((counter%mod )*(temp%mod))%mod;
    }
    return dp[index][col] = counter%mod;
}
int main()
{
    long long n;cin>>n;
    vector<vector<long long>> graph(n+1, vector<long long> ());
    for(long long i=0;i<n-1; i++) 
    {
        long long x,y;cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dp.clear(); dp.resize(n+1, vector<long long> (2, -1));
    long long a = recursor(graph, 1, 0, -1);
    long long b = recursor(graph, 1, 1, -1);
    cout<<(a%mod+b%mod)%mod<<endl;
}