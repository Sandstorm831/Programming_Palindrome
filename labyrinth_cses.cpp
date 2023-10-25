#include <bits/stdc++.h>
using namespace std;
vector<char> dL = {'D', 'R', 'U', 'L'};
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
unordered_map<char, pair<int,int>> ump;
bool checker(int x, int y, int n, int m)
{
    if(x <0 || x>=n || y<0 || y>=m) return false;
    return true;
}
int main()
{
    ump['D'] = make_pair(-1,0);
    ump['R'] = make_pair(0,-1);
    ump['U'] = make_pair(1,0);
    ump['L'] = make_pair(0,1);
    int n,m; cin>>n>>m;
    vector<string> graph(n);
    for(int i=0; i<n; i++) cin>>graph[i];
    pair<int,int> s,e;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++)
    {
        if(graph[i][j] == 'A') s.first = i, s.second = j;
        if(graph[i][j] == 'B') e.first = i, e.second = j;
    }
    vector<vector<char>> dp(n, vector<char> (m));
    vector<vector<bool>> fid(n, vector<bool> (m, false));
    queue<pair<int,int>> q;
    q.push(make_pair(s.first, s.second));
    while(!q.empty())
    {
        pair<int,int> kp = q.front(); q.pop();
        int x = kp.first;
        int y = kp.second;
        if(x == e.first && y == e.second) break;
        fid[x][y] = true;
        for(int i=0; i<4; i++)
        {
            int xx = x+dx[i];
            int yy = y+dy[i];
            char c = dL[i];
            if(checker(xx, yy, n, m) && (graph[xx][yy] == '.' || graph[xx][yy] == 'B') && !fid[xx][yy])
            {
                fid[xx][yy]=true;
                q.push(make_pair(xx,yy));
                dp[xx][yy] = c;
            }
        }
    }
    if(!fid[e.first][e.second]) cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        int xx = e.first, yy = e.second;
        string con="";
        while(xx != s.first || yy != s.second)
        {
            char t = dp[xx][yy];
            con+=t;
            xx += ump[t].first;
            yy += ump[t].second;
        }
        reverse(con.begin(), con.end());
        cout<<con.size()<<endl;
        cout<<con<<endl;
    }
}