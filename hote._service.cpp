#include <bits/stdc++.h>
using namespace std;
/* MLE ERROR
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, -1, 0, 1};
vector<vector<int>> dist_graph;
bool checker(int x, int y, int xl, int yl)
{
    if(x<0 || y<0 || x>=xl || y>=yl) return false;
    return true;
}
void bfs(int x, int y)
{
    // cout<<"here ";
    int a = dist_graph.size();
    int b = dist_graph[0].size();
    int dist=0;
    vector<vector<bool>> visited(a, vector<bool> (b,false));
    queue<pair<int,pair<int,int>>> q;
    q.push(make_pair(0, make_pair(x,y)));
    dist_graph[x][y]=0;
    while(!q.empty())
    {
        pair<int,pair<int,int>> idx = q.front();
        q.pop();
        visited[idx.second.first][idx.second.second]=true;
        for(int i=0; i<4; i++)
        {
            int xx = idx.second.first + dx[i];
            int yy = idx.second.second + dy[i];
            if(checker(xx, yy, a-1, b-1) && !visited[xx][yy])
            {
                q.push(make_pair(idx.first+1, make_pair(xx, yy)));
                if(dist_graph[xx][yy] > idx.first+1) 
                {
                    dist_graph[xx][yy] = idx.first+1;
                }
            }
        }
    }
}
vector<int> Solution::nearestHotel(vector<vector<int> > &A, vector<vector<int> > &B) {
    int n = A.size(); 
    int m = A[0].size();
    dist_graph.clear();
    dist_graph.resize(n+1, vector<int> (m+1, INT_MAX));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(A[i][j] ==  1) bfs(i, j);
        }
    }
    vector<int> final;
    for(int i=0; i<B.size(); i++)
    {
        final.push_back(dist_graph[B[i][0]-1][B[i][1]-1]);
    }
    return final;
}
*/

vector<int> nearestHotel(vector<vector<int> > &A, vector<vector<int> > &B)
{
    vector<vector<int>>dp(A.size(),vector<int>(A[0].size()));
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            dp[i][j]=10000000;
            if(A[i][j]==1)
                dp[i][j]=0;
            if(i>0)
                dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
            if(j>0)
                dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
        }
    }
    for(int i=A.size()-1;i>=0;i--){
        for(int j=A[i].size()-1;j>=0;j--){
            if(i<A.size()-1)
                dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
            if(j<A[i].size()-1)
                dp[i][j]=min(dp[i][j],dp[i][j+1]+1);
        }
    }
    vector<int>ans(B.size());
    for(int i=0;i<B.size();i++)
        ans[i]=dp[B[i][0]-1][B[i][1]-1];
    return ans;  
}