#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1, 0};
vector<int> dy = {0, 1};
bool checker(int x, int y, int n, int m)
{
    if(x<n && x>=0 && y<m && y>=0) return true;
    return false;
}
vector<vector<int>> dp;
const int mod = 1e9+7;
int recursor(vector<vector<char>>& graph, int x, int y, int n, int m)
{
    if(x == n-1 && y == m-1) return 1;
    else if(dp[x][y] != -1) return dp[x][y]%mod;
    int counter=0;
    for(int i=0; i<=1; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(checker(xx, yy, n, m) && graph[xx][yy] == '.')
        {
            counter = (counter%mod + recursor(graph, xx, yy, n, m)%mod)%mod;
        }
    }
    return dp[x][y] = counter%mod;
}
int main()
{
    int n, m;cin>>n>>m;
    vector<vector<char>> graph(n, vector<char> (m));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++) cin>>graph[i][j];
    }
    dp.clear();dp.resize(n+1, vector<int> (m+1, -1));
    cout<<recursor(graph, 0, 0, n, m)<<endl;
}