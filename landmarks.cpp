#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> graph;
vector<int> final;
int maxx;
void dfs(int node, vector<int>& ans, int level, int markup, vector<bool>& vis)
{6
    if(vis[node]) return;
    ans.push_back(node);
    int n = ans.size();
    if(maxx < ans.size()) final = ans;
    maxx = max(maxx, n);
    if(markup == 0) return;
    vis[node]=true;
    for(int i=0; i<graph[node].size(); i++)
    {
        if(!vis[graph[node][i].first] && markup >= graph[node][i].second)
        {
            dfs(graph[node][i].first, ans, level+1, markup-graph[node][i].second, vis);
        }
    }
    vis[node]=false;
    ans.pop_back();
}
void optimalPath(int N, int M, int price, vector<int>& source, vector<int>& dest, vector<int>& weight)
{
    graph.clear();
    graph.resize(101, vector<pair<int,int>> ());
    for(int i=0; i<source.size(); i++)
    {
        graph[source[i]].push_back(make_pair(dest[i], weight[i]));
        graph[dest[i]].push_back(make_pair(source[i], weight[i]));
    }
    int markup = price/2;
    final.clear();
    maxx = INT_MIN;
    vector<int> ans;
    vector<bool> vis(N+1, false);
    dfs(1, ans, 1, markup, vis);
    for(int i=0; i<final.size(); i++) cout<<final[i]<<" ";
    for(int i = final.size()-2; i>=0; i--) cout<<final[i]<<" ";
}
int main()
{
    int N, M, price;
    cin>>N>>M>>price;
    vector<int> source(M), dest(M), weight(M);
    for(int i=0; i<M; i++) cin>>source[i]>>dest[i]>>weight[i];
    optimalPath(N, M, price, source, dest, weight);
    return 0;
}