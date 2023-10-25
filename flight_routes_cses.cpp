#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m, k;cin>>n>>m>>k;
    vector<vector<pair<long long,long long>>> graph(n+1, vector<pair<long long,long long>> ());
    for(long long i=0; i<m; i++) 
    {
        long long x, y, z; cin>>x>>y>>z;
        graph[x].push_back(make_pair(y, z));
    } 
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
    pq.push(make_pair(0,1));
    vector<vector<long long>> sore(n+1, vector<long long> (k, LLONG_MAX));
    while(!pq.empty())
    {
        pair<long long,long long> p = pq.top();pq.pop();
        if(p.first > sore[p.second][k-1]) continue;
        else
        {
            for(long long i=0;i<graph[p.second].size();i++)
            {
                if(sore[graph[p.second][i].first][k-1] > graph[p.second][i].second + p.first)
                {
                    sore[graph[p.second][i].first][k-1] = graph[p.second][i].second + p.first;
                    pq.push(make_pair(sore[graph[p.second][i].first][k-1], graph[p.second][i].first));
                    sort(sore[graph[p.second][i].first].begin(), sore[graph[p.second][i].first].end());
                }
            }
        }
    }
    for(long long i=0; i<k; i++)
    {
        cout<<sore[n][i]<<" ";
    }
}