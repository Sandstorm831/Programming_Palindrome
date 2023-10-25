#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long cases;cin>>cases;
    while(cases--)
    {
        long long v,k;cin>>v>>k;
        vector<vector<pair<long long,long long>>> graph(v+1, vector<pair<long long,long long>> ());
        for(long long i=0; i<k; i++)
        {
            long long a,b,c; cin>>a>>b>>c;
            graph[a].push_back(make_pair(b, c));
        }
        long long x, y;cin>>x>>y;
        vector<long long> dist(v+1, INT_MAX);
        dist[x] = 0;
        vector<bool> vis(v+1, false);
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        pq.push(make_pair(0, x));
        while(!pq.empty())
        {
            long long node = pq.top().second;
            long long dis = pq.top().first;
            pq.pop();
            if(node == y) break;
            if(vis[node]) continue;
            vis[node] = true;
            for(long long i=0; i<graph[node].size(); i++)
            {
                if(dist[graph[node][i].first] > dis + graph[node][i].second)
                {
                    dist[graph[node][i].first] = dis+graph[node][i].second;
                    pq.push(make_pair(dist[graph[node][i].first], graph[node][i].first));
                }
            }
        }
        if(dist[y] == INT_MAX) cout<<"NO"<<endl;
        else cout<<dist[y]<<endl;
    }
}