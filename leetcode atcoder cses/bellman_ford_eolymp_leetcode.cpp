#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;cin>>n>>m;
    vector<vector<long long>> edges(m, vector<long long> (3));
    for(long long i=0; i<m; i++)
    {
        long long x,y,z;cin>>x>>y>>z;
        edges[i][0] = x;
        edges[i][1] = y;
        edges[i][2] = z;
    }
    vector<long long> dist(n+1, 30000);
    dist[1] = 0;
    for(long long j=0; j<n-1; j++)
    {
        for(long long i=0; i<edges.size(); i++)
        {
            if(dist[edges[i][0]] < 30000)
            {
                dist[edges[i][1]] = min(dist[edges[i][1]], dist[edges[i][0]]+edges[i][2]);
            }
        }
    }
    for(long long i=1; i<dist.size();i++) cout<<dist[i]<<" ";
    cout<<endl;
    return 0;
}