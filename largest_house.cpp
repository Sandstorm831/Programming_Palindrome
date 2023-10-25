#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
bool checker(int x, int y, int n, int m)
{
    if(x <0 || x>=n || y<0 || y>=m) return false;
    return true;
}
int dfs(vector<vector<int>>& graph, vector<vector<bool>>& vis, int x, int y)
{
    if(vis[x][y]) return 0;
    vis[x][y] = true;
    int counter=1;
    for(int i=0; i<4; i++)
    {
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(checker(xx, yy, graph.size(), graph[0].size()) && !vis[xx][yy] && graph[xx][yy])
        {
            counter += dfs(graph, vis, xx, yy);
        }
    }
    return counter;
}
int main()
{
    int n, m;cin>>n>>m;
    vector<vector<int>> graph(n, vector<int> (m));
    for(int i=0; i<n; i++) for(int j=0;j<m; j++) cin>>graph[i][j];
    vector<vector<bool>> vis(n,vector<bool> (m,false));
    int maxx = 0;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++)
    {
        if(!vis[i][j])
        {
            maxx = max(maxx, dfs(graph, vis, i, j));
        }
    }
    cout<<maxx-1;
}