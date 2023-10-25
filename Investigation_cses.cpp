#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
int main()
{
    long long n,m; cin>>n>>m;
    vector<vector<pair<long long,long long>>> graph(n+1, vector<pair<long long,long long>> ());
    for(long long i=0; i<m; i++)
    {
        long long x,y,z;cin>>x>>y>>z;
        graph[x].push_back(make_pair(y,z));
    }
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
    vector<long long> dist(n+1, LLONG_MAX);
    vector<long long> num(n+1, INT_MAX);
    vector<long long> minf(n+1, INT_MAX);
    vector<long long> maxf(n+1, INT_MAX);
    vector<bool> vis(n+1, false);
    dist[1] = 0;
    num[1]=1;
    maxf[1] = 0;
    minf[1] = 0;
    pq.push(make_pair(0, 1));
    while(!pq.empty())
    {
        pair<long long,long long> p = pq.top(); pq.pop();
        if(vis[p.second]) continue;
        vis[p.second] = true;
        for(long long i=0;i<graph[p.second].size(); i++)
        {
            if(dist[graph[p.second][i].first] > graph[p.second][i].second + p.first)
            {
                dist[graph[p.second][i].first] = graph[p.second][i].second + p.first;
                num[graph[p.second][i].first] = num[p.second];
                minf[graph[p.second][i].first] = minf[p.second]+1;
                maxf[graph[p.second][i].first] = maxf[p.second]+1;
                pq.push(make_pair(dist[graph[p.second][i].first], graph[p.second][i].first));
            }
            else if(dist[graph[p.second][i].first] == graph[p.second][i].second + p.first)
            {
                num[graph[p.second][i].first] = (num[graph[p.second][i].first] + num[p.second])%mod;
                minf[graph[p.second][i].first] = min(minf[graph[p.second][i].first], minf[p.second]+1);
                maxf[graph[p.second][i].first] = max(maxf[graph[p.second][i].first], maxf[p.second]+1);
            }
        }
    }
    // for(long long i=1;i < dist.size(); i++) cout<<dist[i]<<" ";
    // cout<<endl;
    // for(long long i=1;i < dist.size(); i++) cout<<num[i]<<" ";
    // cout<<endl;
    // for(long long i=1;i < dist.size(); i++) cout<<minf[i]<<" ";
    // cout<<endl;
    // for(long long i=1;i < dist.size(); i++) cout<<maxf[i]<<" ";
    // cout<<endl;
    cout<<dist[n]<<" "<<num[n]<<" "<<minf[n]<<" "<<maxf[n]<<endl;
}