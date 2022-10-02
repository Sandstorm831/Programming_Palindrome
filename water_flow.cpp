/* Problem Link - https://www.interviewbit.com/problems/water-flow/
vector<vector<int>> red, blue;
bool checker(int x, int y, int n, int m)
{
    if(x<0 || y<0 || x>=n || y>=m) return false;
    return true;
}
int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    queue<pair<int,int>> q;
    int ans=0;
    red.clear();
    red.resize(n,vector<int> (m,0));
    blue.clear();
    blue.resize(n,vector<int> (m,0));
    for(int i = 1; i<n;i++)
    {
        q.push({i,0});
        blue[i][0]++;
    }
    for(int i=0;i<m;i++)
    {
        q.push({0,i});
        blue[0][i]++;
    }
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};
    while(!q.empty())
    {
        pair<int,int> idx = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x = idx.first+dx[i], y = idx.second+dy[i];
            if(checker(x,y,n,m) && blue[x][y] == 0 && A[x][y] >= A[idx.first][idx.second])
            {
                q.push({x,y});
                blue[x][y] += 1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        q.push({i,m-1});
        red[i][m-1]++;
    }
    for(int i=0;i<m-1;i++)
    {
        q.push({n-1,i});
        red[n-1][i]++;
    }
    while(!q.empty())
    {
        pair<int,int> idx = q.front();
        if(red[idx.first][idx.second] == 1 && blue[idx.first][idx.second] == 1) ans++;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x = idx.first+dx[i], y = idx.second+dy[i];
            if(checker(x,y,n,m) && red[x][y] == 0 && A[x][y] >= A[idx.first][idx.second])
            {
                q.push({x,y});
                red[x][y] +=1 ;
            }
        }
    }
    return ans;
}
*/
vector<vector<int>> red, blue;
bool checker(int x, int y, int n, int m)
{
    if(x<0 || y<0 || x>=n || y>=m) return false;
    return true;
}
int main()
{
    vector<vector<int>> A = {{1, 2, 2, 3, 5},
                            {3, 2, 3, 4, 4},
                            {2, 4, 5, 3, 1},
                            {6, 7, 1, 4, 5},
                            {5, 1, 1, 2, 4}
                            }
    int n = A.size(), m = A[0].size();
    queue<pair<int,int>> q;
    int ans=0;
    red.clear();
    red.resize(n,vector<int> (m,0));
    blue.clear();
    blue.resize(n,vector<int> (m,0));
    for(int i = 1; i<n;i++)
    {
        q.push({i,0});
        blue[i][0]++;
    }
    for(int i=0;i<m;i++)
    {
        q.push({0,i});
        blue[0][i]++;
    }
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};
    while(!q.empty())
    {
        pair<int,int> idx = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x = idx.first+dx[i], y = idx.second+dy[i];
            if(checker(x,y,n,m) && blue[x][y] == 0 && A[x][y] >= A[idx.first][idx.second])
            {
                q.push({x,y});
                blue[x][y] += 1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        q.push({i,m-1});
        red[i][m-1]++;
    }
    for(int i=0;i<m-1;i++)
    {
        q.push({n-1,i});
        red[n-1][i]++;
    }
    while(!q.empty())
    {
        pair<int,int> idx = q.front();
        if(red[idx.first][idx.second] == 1 && blue[idx.first][idx.second] == 1) ans++;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x = idx.first+dx[i], y = idx.second+dy[i];
            if(checker(x,y,n,m) && red[x][y] == 0 && A[x][y] >= A[idx.first][idx.second])
            {
                q.push({x,y});
                red[x][y] +=1 ;
            }
        }
    }
    return ans;
}