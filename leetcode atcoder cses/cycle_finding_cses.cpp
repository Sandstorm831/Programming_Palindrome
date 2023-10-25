#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;cin>>n>>m;
    vector<vector<long long>> graph;
    for(long long i=0; i<m; i++)
    {
        long long x, y, w;cin>>x>>y>>w;
        vector<long long> temp;temp.push_back(x), temp.push_back(y), temp.push_back(w);
        graph.push_back(temp);
    }
    vector<long long> dist(n+1, 0), par(n+1, -1);
    long long x;
 
    for(long long i=0; i<n; i++)
    {
        x = -1;
        for(long long j=0;j<graph.size();j++)
        {
            if(dist[graph[j][1]] > dist[graph[j][0]] + graph[j][2])
            {
                dist[graph[j][1]] = dist[graph[j][0]] + graph[j][2];
                par[graph[j][1]] = graph[j][0];
                x = graph[j][1];
            }
        }
    }
    if(x == -1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        long long node = x;
        for(long long i=0; i<n;i++) node = par[node];
        vector<long long> path;
        for(long long curr = node;;curr = par[curr])
        {
            path.push_back(curr);
            if(curr == node && path.size() > 1) break;
        }
        reverse(path.begin(), path.end());
        cout<<"YES"<<endl;
        for(long long i=0; i<path.size(); i++) cout<<path[i]<<" ";
        cout<<endl;
    }
}