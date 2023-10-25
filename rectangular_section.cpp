// Quesiton Link - 
// solution 
#include <bits/stdc++.h>
using namespace std;
int checker(int x, int y, int n, int m)
{
    if(x>=0 && y>=0 && x<n && y<m) return true;
    return false;
}
int solution(int N, int M, vector<int>& X1, vector<int>& Y1, vector<int>& X2, vector<int>& Y2)
{
    vector<vector<int>> graph(N, vector<int> (M, 0));
    for(int i=0; i<X1.size();i++)
    {
        for(int k = X1[i]; k<=X2[i];k++)
        {
            for(int l = Y1[i]; l<=Y2[i];l++)
            {
                if(graph[k][l] != 0) continue;
                else graph[k][l] = 1;
            }
        }
    }
    queue<pair<int,int>> q;
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    q.push(make_pair(0,0));
    q.push(make_pair(INT_MAX, INT_MAX));
    vector<vector<bool>> vis(N, vector<bool> (M, false));
    int dist = 0;
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        if(p.first == INT_MAX && p.second == INT_MAX)
        {
            if(q.empty()) continue;
            else q.push(make_pair(INT_MAX, INT_MAX));
            dist++;
            continue;
        }
        vis[p.first][p.second] = true;
        if(p.first == N-1 && p.second == M-1) return dist;
        else
        {
            for(int i=0; i<4; i++)
            {
                int xx = p.first+dx[i];
                int yy = p.second+dy[i];
                if(checker(xx, yy, N, M) && graph[xx][yy] == 0 && !vis[xx][yy])
                {
                    q.push(make_pair(xx, yy));
                    vis[xx][yy] = true;
                }
            }
        }
    }
    return -1;
}
int main()
{
    int N = 6, M=4;
    vector<int> X1 = {2,1,4};
    vector<int> Y1 = {0,1,3};
    vector<int> X2 = {2,3,4};
    vector<int> Y2 = {2,1,3};
    cout<<solution(N, M, X1, Y1, X2, Y2)<<endl;
}