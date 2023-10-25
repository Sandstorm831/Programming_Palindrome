#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m, q; cin>>n>>m>>q;
    vector<vector<long long>> graph(n+1, vector<long long> (n+1, LLONG_MAX));
    for(long long i=0; i<=n; i++) graph[i][i]=0;
    for(long long i=0;i<m; i++)
    {
        long long x,y, z;cin>>x>>y>>z;
        graph[x][y]=min(graph[x][y],z);
        graph[y][x]=graph[x][y];
    }
    for(long long k=1; k<=n; k++)
    {
        for(long long i=1;i<=n; i++)
        {
            for(long long j=1;j<=n; j++)
            {
                if(graph[i][k] < LLONG_MAX && graph[k][j] < LLONG_MAX)
                {
                    graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
                    graph[j][i] = graph[i][j];
                }
            }
        }
    }
    for(long long i=0;i<q;i++)
    {
        long long x,y;cin>>x>>y;
        cout<<(graph[x][y] == LLONG_MAX ? -1 : graph[x][y])<<endl;
    }
}