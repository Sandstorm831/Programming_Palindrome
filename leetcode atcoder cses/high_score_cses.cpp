#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;cin>>n>>m;
    vector<vector<long long>> edges(m, vector<long long> (3)), ledges(m, vector<long long> (3));
    for(long long i=0;i<m; i++)
    {
        long long x,y,z;cin>>x>>y>>z;
        edges[i][0] = x;
        edges[i][1] = y;
        edges[i][2] = -z;
        ledges[i][0] = y;
        ledges[i][1] = x;
        ledges[i][2] = -z;
    }
    vector<long long> par(n+1, -1);
    vector<long long> dist(n+1, LLONG_MAX), disl(n+1, LLONG_MAX);
    dist[1] = 0;
    long long xx;
    vector<long long> dupl;
    for(long long i=0; i < n; i++)
    {
        xx = -1;
        dupl.clear();
        long long es = 1ll*edges.size();
        for(long long j=0; j<es; j++)
        {
            if(dist[edges[j][0]] < LLONG_MAX)
            {
                if(dist[edges[j][0]]+edges[j][2] < dist[edges[j][1]] )
                {
                    dist[edges[j][1]] = max(LLONG_MIN, dist[edges[j][0]]+edges[j][2]);
                    par[edges[j][1]] = edges[j][0];
                    xx = edges[j][1];
                    dupl.push_back(xx);
                }
            }
        }
    }
    bool yup = true;
    if(xx != -1)
    {
        set<long long> omni;
        for(long long t = 0; t<dupl.size(); t++)
        {
            long long p = dupl[t];
            vector<long long> path;
            for(int i=0; i<n; i++) p = par[p];
            for(long long cur = p; ; cur = par[cur])
            {
                if(cur == p && path.size() > 1) break;
                path.push_back(cur);
            }
            for(long long j=0; j<path.size(); j++) omni.insert(path[j]);
        }
        disl[n] = 0;
        for(long long i=0; i < n; i++)
        {
            long long es = 1ll*ledges.size();
            for(long long j=0; j<es; j++)
            {
                if(disl[ledges[j][0]] < LLONG_MAX)
                {
                    if(disl[ledges[j][0]]+ledges[j][2] < disl[ledges[j][1]] )
                    {
                        disl[ledges[j][1]] = max(LLONG_MIN, disl[ledges[j][0]]+ledges[j][2]);
                    }
                }
            }
        }
        vector<long long> path;
        for(auto itr = omni.begin(); itr != omni.end(); itr++) path.push_back(*itr);
        for(long long j = 0; j<path.size(); j++)
        {
            if(disl[path[j]] != LLONG_MAX) 
            {
                cout<<-1<<endl;
                yup = false;
                break;
            }
        }

    }
    if(yup) cout<<-dist[n]<<endl;
}