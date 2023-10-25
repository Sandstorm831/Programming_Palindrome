#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<bool> vis;
vector<int> ans;
vector<bool> temp;
bool is_cycle;
void dfs(int node)
{
    if(temp[node]) {is_cycle=true; return;}
    vis[node]=true;
    temp[node]=true;
    for(int i=0;i<graph[node].size(); i++)
    {
        if(!vis[graph[node][i]] && !temp[graph[node][i]]) dfs(graph[node][i]);
        else if(temp[graph[node][i]])
        {
            is_cycle = true;return;
        }
    }
    ans.push_back(node);
    temp[node]=false;
}
int main()
{
    int n,m;cin>>n>>m;
    graph.clear();graph.resize(n+1, vector<int> ());
    for(int i=0; i<m; i++)
    {
        int x, y;cin>>x>>y;
        graph[x].push_back(y);
    }
    vis.clear(); vis.resize(n+1, false);
    temp.clear(); temp.resize(n+1, false);
    ans.clear();
    is_cycle = false;
    for(int i=1; i<=n; i++)
    {
        if(!vis[i]) dfs(i);
    }
    if(is_cycle) cout<<"IMPOSSIBLE"<<endl;
    else
    {
        reverse(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

}