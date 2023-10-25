#include <bits/stdc++.h>
using namespace std;
bool checker(int x, int y, int n,int m)
{
    if(x < 0 || x>=n || y < 0 || y>=m) return false;
    return true;
}
void bfs(vector<string>& graph, vector<vector<int>>& dump, vector<vector<bool>>& vis, int x, int y)
{
    // cout<<"init"<<endl;
    queue<pair<int,pair<int,int>>> q;
    q.push(make_pair(0,make_pair(x,y)));
    vector<int> dx = {1,0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    while(!q.empty())
    {
        pair<int,pair<int,int>> p = q.front();q.pop();
        int x = p.second.first;
        int y = p.second.second;
        int dd = p.first;
        dump[x][y] = min(dump[x][y], dd);
        vis[x][y] = true;
        for(int i=0; i<4; i++)
        {
            int xx = x+dx[i];
            int yy = y+dy[i];
            if(checker(xx, yy, graph.size(), graph[0].size()) && graph[xx][yy] != '#' && (dump[xx][yy] == INT_MAX || dump[xx][yy] > dd+1))
            {
                if(graph[xx][yy] == 'M' && vis[xx][yy]) continue;
                else if(graph[xx][yy] == 'M') 
                {
                    q.push(make_pair(0, make_pair(xx,yy)));
                    dump[xx][yy] = 0;
                }
                else 
                {
                    q.push(make_pair(dd+1, make_pair(xx,yy)));
                    dump[xx][yy] = min(dump[xx][yy], dd+1);
                }
                vis[xx][yy] = true;
            }
        }
    }
}
void bfs2(vector<string>& graph, vector<vector<int>>& dump, int x, int y)
{
    queue<pair<int,int>> q;
    vector<vector<bool>> vis(graph.size(), vector<bool> (graph[0].size(), false));
    int d = 0;
    q.push(make_pair(x,y));
    q.push(make_pair(INT_MAX, INT_MAX));
    vector<int> dx = {1,0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    while(!q.empty())
    {
        pair<int,int> p = q.front();q.pop();
        int x = p.first;
        int y = p.second;
        if(x == INT_MAX)
        {
            if(q.empty()) continue;
            d++;q.push(make_pair(INT_MAX,INT_MAX));
            continue;
        }
        dump[x][y] = min(dump[x][y], d);
        vis[x][y] = true;
        for(int i=0; i<4; i++)
        {
            int xx = x+dx[i];
            int yy = y+dy[i];
            if(checker(xx, yy, graph.size(), graph[0].size()) && graph[xx][yy] != '#' && !vis[xx][yy])
            {
                q.push(make_pair(xx,yy));
                vis[xx][yy] = true;
            }
        }
    }
}
int main()
{
    int n,m; cin>>n>>m;
    vector<string> graph(n);
    for(int i=0; i<n; i++) cin>>graph[i];
    vector<pair<int,int>> vp;
    pair<int,int> a;
    for(int i=0;i<n; i++) for(int j=0; j<m;j++)
    {
        if(graph[i][j] == 'M') vp.push_back(make_pair(i,j));
        else if(graph[i][j] == 'A') a = make_pair(i,j);
    }
    vector<vector<int>> dist(n, vector<int> (m, INT_MAX)), d(n, vector<int> (m, INT_MAX));
    vector<vector<bool>> visit(n, vector<bool> (m, false));
    for(int i=0; i<vp.size(); i++)
    {
        // cout<<" ---------------------- "<<endl;
        if(!visit[vp[i].first][vp[i].second]) bfs(graph, dist, visit, vp[i].first, vp[i].second);
    }
    visit.clear(); visit.resize(n, vector<bool> (m, false));
    bfs2(graph, d,  a.first, a.second);
    vector<vector<char>> dp(n, vector<char> (m, 'X'));
    queue<pair<int,int>> q;
    vector<vector<bool>> vis(graph.size(), vector<bool> (graph[0].size(), false));
    q.push(make_pair(a.first,a.second));
    vector<int> dx = {1,0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    vector<char> dir = {'D', 'R', 'U', 'L'};
    unordered_map<char,pair<int,int>> ump;
    ump['D'] = {-1,0};
    ump['U'] = {1, 0};
    ump['L'] = {0, 1};
    ump['R'] = {0,-1};
    int x=-1,y=-1;
    while(!q.empty())
    {
        pair<int,int> p = q.front();q.pop();
        x = p.first;
        y = p.second;
        if(x == 0 || x == n-1 || y == 0 || y == m-1)
        {
            break;
        }
        vis[x][y] = true;
        for(int i=0; i<4; i++)
        {
            int xx = x+dx[i];
            int yy = y+dy[i];
            if(checker(xx, yy, graph.size(), graph[0].size()) && graph[xx][yy] != '#' && !vis[xx][yy] && dist[xx][yy]>d[xx][yy])
            {
                q.push(make_pair(xx,yy));
                dp[xx][yy] = dir[i];
                vis[xx][yy] = true;
            }
        }
    }
    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<m;j++) 
    //     {
    //         if(dist[i][j] == INT_MAX) cout<<"X ";
    //         else cout<<dist[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"------------------"<<endl;
    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<m;j++) 
    //     {
    //         if(dist[i][j] == INT_MAX) cout<<"X ";
    //         else cout<<d[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    if(x == 0 || x == n-1 || y == 0 || y == m-1)
    {
        cout<<"YES"<<endl;
        string fin="";
        while(x != a.first || y != a.second)
        {
            char o = dp[x][y];
            fin+=dp[x][y];
            x += ump[o].first;
            y += ump[o].second;
        }
        reverse(fin.begin(), fin.end());
        cout<<fin.size()<<endl<<fin<<endl;

    }
    else 
    {
        cout<<"NO"<<endl;
    }
}   
/*
8 8
###MMMMM
#.AMMMMM
#.#MMMMM
#.#MMMMM
#.#MMMMM
#.#MMMMM
#..MMMMM
#.#MMMMM
*/
/*
4 10
..........
#M........  
#A.......#
##########
*/