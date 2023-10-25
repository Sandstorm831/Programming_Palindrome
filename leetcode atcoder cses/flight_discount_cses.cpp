#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m; cin>>n>>m;
    vector<vector<pair<long long,long long>>> graph1(n+1, vector<pair<long long,long long>> ()), graph2(n+1, vector<pair<long long,long long>> ());
    for(long long i=0; i<m; i++)
    {
        long long a,b,c;cin>>a>>b>>c;
        graph1[a].push_back(make_pair(b, c));
        graph2[b].push_back(make_pair(a, c));
    }
    vector<long long> dist1(n+1, LLONG_MAX - 1ll*INT_MAX);
    vector<bool> vis1(n+1, false);
    vector<long long> par1(n+1, -1);
    dist1[1] = 0;
    priority_queue<pair<pair<long long,long long>,long long>, vector<pair<pair<long long,long long>,long long>>, greater<pair<pair<long long,long long>,long long>>> pq1;
    pq1.push(make_pair(make_pair(0, 1), -1));
    while(!pq1.empty())
    {
        long long node = pq1.top().first.second;
        long long dis = pq1.top().first.first;
        long long p = pq1.top().second;
        pq1.pop();
        if(vis1[node]) continue;
        vis1[node]=true;
        par1[node] = p;
        long long cc = graph1[node].size();
        for(long long i=0 ;i<cc; i++)
        {
            if(dist1[graph1[node][i].first] > dis + graph1[node][i].second)
            {
                dist1[graph1[node][i].first] = dis+graph1[node][i].second;
                pq1.push(make_pair(make_pair(dist1[graph1[node][i].first], graph1[node][i].first), node));
            }
        }
    }
    ///////////////////////////////////////
    vector<long long> dist2(n+1, LLONG_MAX - 1ll*INT_MAX);
    vector<bool> vis2(n+1, false);
    vector<long long> par2(n+1, -1);
    dist2[n] = 0;
    priority_queue<pair<pair<long long,long long>,long long>, vector<pair<pair<long long,long long>,long long>>, greater<pair<pair<long long,long long>,long long>>> pq2;
    pq2.push(make_pair(make_pair(0, n), -1));
    while(!pq2.empty())
    {
        long long node = pq2.top().first.second;
        long long dis = pq2.top().first.first;
        long long p = pq2.top().second;
        pq2.pop();
        if(vis2[node]) continue;
        vis2[node]=true;
        par2[node] = p;
        long long cc = graph2[node].size();
        for(long long i=0 ;i<cc; i++)
        {
            if(dist2[graph2[node][i].first] > dis + graph2[node][i].second)
            {
                dist2[graph2[node][i].first] = dis+graph2[node][i].second;
                pq2.push(make_pair(make_pair(dist2[graph2[node][i].first], graph2[node][i].first), node));
            }
        }
    }
    long long counter = LLONG_MAX;
    long long kst = graph1.size();
    for(long long i=1; i<kst; i++)
    {
        long long sst = graph1[i].size();
        for(long long j=0; j<sst; j++)
        {
            counter = min(counter, dist1[i]+dist2[graph1[i][j].first]+(graph1[i][j].second / 2));
        }
    }
    cout<<counter<<endl;
}