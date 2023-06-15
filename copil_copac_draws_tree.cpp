#include <bits/stdc++.h>
using namespace std;
int maxx=INT_MIN;
void dfs(vector<vector<pair<int,int>>>& graph, vector<bool>& vis, int node, int maxl, int doge)
{
    if(vis[node]) return;
    vis[node]=true;
    for(int i=0; i<graph[node].size(); i++)
    {
        if(!vis[graph[node][i].first]) 
        {
            if(graph[node][i].second < maxl) dfs(graph, vis, graph[node][i].first, graph[node][i].second, doge+1);
            else dfs(graph, vis,graph[node][i].first,graph[node][i].second, doge);
        }
    }
    maxx = max(maxx, doge);
}
int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        maxx = INT_MIN;
        int n; cin>>n;
        vector<vector<pair<int,int>>> graph(n+1, vector<pair<int,int>> ());
        for(int i=0;i<n-1; i++)
        {
            int x, y; cin>>x>>y;
            graph[x].push_back(make_pair(y,i+1));
            graph[y].push_back(make_pair(x, i+1));
        }
        vector<bool> vis(n+1, false);
        // cout<<maxx<<endl;
        dfs(graph, vis, 1, 0, 0);
        cout<<maxx+1<<endl;
    }
}