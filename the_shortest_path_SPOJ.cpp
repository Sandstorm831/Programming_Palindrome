#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;cin>>cases;
    while(cases--)
    {
        int n;cin>>n;
        vector<vector<pair<int,int>>> graph(n+1, vector<pair<int,int>> ());
        unordered_map<string,int> ump;
        int index = 1;
        while(index<=n)
        {
            string x;cin>>x;
            ump[x] = index;
            int a;cin>>a;
            while(a--)
            {
                int x,y;cin>>x>>y;
                graph[index].push_back(make_pair(x, y));
            }
            index++;
        }
        int aa;cin>>aa;
        while(aa--)
        {
            string x,y;cin>>x>>y;
            int xx = ump[x];
            int yy = ump[y];
            vector<int> dist(n+1, INT_MAX);
            vector<bool> vis(n+1, false);
            dist[xx] = 0;
            priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
            pq.push(make_pair(0, xx));
            while(!pq.empty())
            {
                int node = pq.top().second;
                int d = pq.top().first;
                vis[node] = 1;
                if(node == yy) break;
                pq.pop();
                for(int i=0; i<graph[node].size(); i++)
                {
                    if(!vis[graph[node][i].first])
                    {
                        // dist[graph[node][i].first] = min(dist[graph[node][i].first], );
                        if(dist[graph[node][i].first] > d + graph[node][i].second)
                        {
                            dist[graph[node][i].first] = d+graph[node][i].second;
                            pq.push(make_pair(dist[graph[node][i].first], graph[node][i].first));
                        }
                    }
                }
            }
            cout<<dist[yy]<<endl;
        }
        
    }
}