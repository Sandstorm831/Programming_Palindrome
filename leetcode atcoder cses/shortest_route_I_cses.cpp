#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m; cin>>n>>m;
    vector<vector<pair<long long,long long>>> graph(n+1, vector<pair<long long,long long>> ());
    for(long long i=0; i<m; i++)
    {
        long long a,b,c;cin>>a>>b>>c;
        graph[a].push_back(make_pair(b, c));
    }
    vector<long long> dist(n+1, LLONG_MAX);
    vector<bool> vis(n+1, false);
    dist[1] = 0;
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
    pq.push(make_pair(0, 1));
    while(!pq.empty())
    {
        long long node = pq.top().second;
        long long dis = pq.top().first;
        pq.pop();
        if(vis[node]) continue;
        vis[node]=true;
        long long cc = graph[node].size();
        for(long long i=0 ;i<cc; i++)
        {
            if(dist[graph[node][i].first] > dis + graph[node][i].second)
            {
                dist[graph[node][i].first] = dis+graph[node][i].second;
                pq.push(make_pair(dist[graph[node][i].first], graph[node][i].first));
            }
        }
    }
    for(long long i=1; i<=n; i++) cout<<dist[i]<<" ";
    cout<<endl;
}