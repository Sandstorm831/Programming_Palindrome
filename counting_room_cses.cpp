#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1,0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
bool checker(int x, int y, int n, int m)
{
    if(x >= n || x<0 || y>=m || y<0) return false;
    return true;
}
int main()
{
    int n,m;cin>>n>>m;
    vector<string> vs(n);
    for(int i=0; i<n; i++) cin>>vs[i];
    vector<vector<bool>> vb(n, vector<bool> (m, false));
    vector<pair<int,int>> vp;
    int counter=0;
    for(int i=0;i <n; i++)
    {
        for(int j=0; j<vs[i].size(); j++)
        {
            if(vs[i][j] == '.' && !vb[i][j])
            {
                counter++;
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                while(!q.empty())
                {
                    pair<int,int> pp = q.front();
                    q.pop();
                    vb[pp.first][pp.second]=true;
                    for(int k=0; k<4; k++)
                    {
                        int xx = pp.first + dx[k];
                        int yy = pp.second + dy[k];
                        if(checker(xx, yy, n, m) && vs[xx][yy] == '.' && !vb[xx][yy])
                        {
                            vb[xx][yy] = true;
                            q.push(make_pair(xx,yy));
                        }
                    }
                }
            }
        }
    }
    cout<<counter<<endl;

}