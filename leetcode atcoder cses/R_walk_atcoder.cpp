// Here recursive approach won't work as the input is of size 10^(18)
// long long recursor(vector<vector<long long>>& graph, long long node, long long dist)
// {
//     if(dist == 0) return 1;
//     long long counter=0;
//     for(long long i=0;i<graph[node].size(); i++)
//     {
//         counter = (counter%mod + recursor(graph, graph[node][i], dist-1)%mod)%mod;
//     }
//     return counter;
// }
// long long main()
// {
//     long long n, k;cin>>n>>k;
//     vector<vector<long long>> graph(n+1, vector<long long> ());
//     for(long long i=1; i<=n; i++)
//     {
//         for(long long j=1;j<=n; j++)
//         {
//             long long x;cin>>x;
//             if(x) graph[i].push_back(j);
//         }
//     }
//     long long counter=0;
//     for(long long i=1;i<=n; i++)
//     {
//         counter = (counter%mod + recursor(graph, i, k)%mod)%mod;
//     }
//     cout<<counter<<endl;
// }
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
vector<vector<long long>> matmul(vector<vector<long long>>& a, vector<vector<long long>>& b)
{
    long long n = a.size();
    vector<vector<long long>> ans(n, vector<long long> (n, 0));
    for(long long i=0; i<n; i++)
    {
        for(long long j=0;j<n; j++)
        {
            for(long long k=0; k<n; k++)
            {
                ans[i][j] = (ans[i][j]%mod + (a[i][k]*b[k][j])%mod)%mod;
            }
        }
    }
    return ans;
}
vector<vector<long long>> matrixexp(vector<vector<long long>>& graph, long long k)
{
    if(k == 0)
    {
        for(long long i=0; i<graph.size(); i++)
        {
            for(long long j=0; j<graph.size();j++)
            {
                if( i == j) graph[i][j] = 1;
                else graph[i][j] = 0;
            }
        }
        return graph;
    }
    else if(k == 1) return graph;
    long long n = graph.size();
    vector<vector<long long>> temp = matrixexp(graph, k/2);
    vector<vector<long long>> ans = matmul(temp, temp);
    if(k&1) ans = matmul(ans, graph);
    return ans;
}
int main()
{
    long long n, k; cin>>n>>k;
    vector<vector<long long>> graph(n,vector<long long> (n, 0));
    for(long long i=0; i<n; i++)
    {
        for(long long j=0;j<n; j++)
        {
            cin>>graph[i][j];
        }
    }
    vector<vector<long long>> grh = matrixexp(graph, k);
    long long ans = 0;
    for(long long i=0; i<n; i++) for(long long j=0;j<n;j++){ ans = (ans%mod + grh[i][j]%mod)%mod;}
    cout<<ans<<endl;
}