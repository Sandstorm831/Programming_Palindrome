#include <bits/stdc++.h>
using namespace std;
int dfs(int index, vector<vector<int>>& graph, vector<bool>& vis, vector<int>& dp)
{
    vis[index] = true;
    int maxer = 0;
    if(dp[index] != -1) return dp[index];
    for(int i=0; i<graph[index].size(); i++)
    {
        int counter = INT_MIN;
        if(!vis[graph[index][i]])
        {
            counter = 1+dfs(graph[index][i], graph, vis, dp);
        }
        else counter = 1+dp[graph[index][i]];
        maxer = max(maxer, counter);
    }
    // cout<<index<<" "<<maxer<<endl;
    return dp[index] = maxer;
}
int main()
{
    int n,m;cin>>n>>m;
    vector<pair<int,int>> vp(m);
    for(int i=0; i<m; i++) cin>>vp[i].first>>vp[i].second;
    vector<vector<int>> graph(n+1);
    for(int i=0; i<vp.size(); i++) graph[vp[i].first].push_back(vp[i].second);
    vector<bool> vis(n+1, false);
    vector<int> dp(n+1, -1);
    int maxer = INT_MIN;
    // cout<<"_________________"<<endl;
    for(int i=1;  i<=n; i++)
    {
        int x=INT_MIN;
        if(!vis[i]) x = dfs(i, graph, vis, dp);
        // cout<<x<<endl;
        maxer = max(x, maxer);
    }
    cout<<maxer<<endl;
}