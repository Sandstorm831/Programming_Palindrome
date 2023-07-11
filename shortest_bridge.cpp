// Question Link - https://leetcode.com/problems/shortest-bridge/solutions/3648350/shortest-bridge/
// Solution 

class Solution {
public:
    bool checker(int x, int y, int n, int m)
    {
        if(x >=0 && x<n && y >= 0 && y<m) return true;
        return false;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int firstx=0, firsty=0;
        bool found=false;
        for(int i=0; i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    firstx = i;
                    firsty=j;
                    found = true;
                }
            }
            if(found) break;
        }
        grid[firstx][firsty]=2;
        vector<int> dx = {1,0,-1,0};
        vector<int> dy = {0, 1, 0, -1};
        // vector<vector<bool>> vis(grid.size(), vector<bool> (grid[0].size(),false));
        queue<pair<int,int>> q;
        q.push(make_pair(firstx, firsty));
        queue<pair<int,int>> que;
        que.push(make_pair(firstx, firsty));
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            grid[p.first][p.second]=2;
            // vis[p.first][p.second]=true;
            for(int i=0; i<=3; i++)
            {
                int xx = p.first + dx[i];
                int yy = p.second + dy[i];
                if(checker(xx, yy, grid.size(), grid[0].size()) && grid[xx][yy]==1)
                {
                    q.push(make_pair(xx, yy));
                    que.push(make_pair(xx,yy));
                    // vis[xx][yy]=true;
                    grid[xx][yy]=2;
                }
            }
        }
        que.push(make_pair(INT_MAX, INT_MAX));
        // vis.clear();
        // vis.resize(grid.size(), vector<bool> (grid[0].size(),false));
        int dist=0;
        // cout<<que.size()<<endl;
        while(!que.empty())
        {
            pair<int,int> p = que.front();
            que.pop();
            if(p.first == INT_MAX && p.second == INT_MAX)
            {
                // cout<<"here"<<endl;
                if(que.empty()) continue;
                que.push(make_pair(INT_MAX,INT_MAX));
                dist++;
                continue;
            }
            if(grid[p.first][p.second] == 1) 
            {
                return dist;
            }
            // vis[p.first][p.second]=true;
            // int dist = p.second;
            for(int i=0; i<=3; i++)
            {
                int xx = p.first + dx[i];
                int yy = p.second + dy[i];
                if(checker(xx, yy, grid.size(), grid[0].size()) && grid[xx][yy]!=2)
                {
                    if(grid[xx][yy]==1) return dist;
                    que.push(make_pair(xx, yy));
                    // vis[xx][yy]=true;
                    grid[xx][yy]=2;
                }
            }
            // cout<<que.size()<<endl;
        }
        return dist;

    }
};