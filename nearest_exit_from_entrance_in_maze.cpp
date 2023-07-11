// Question Link - https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/
// Solution

class Solution {
public:
    bool checker(int x, int y, int n, int m)
    {
        if(x>=0 && x<n && y>=0 && y<m) return true;
        return false;
    }
    bool isexit(int x, int y, int n, int m, vector<vector<char>>& maze)
    {
        if(maze[x][y]=='.')
        {
            if(x == 0 || x == n-1 || y == 0 || y == m-1) return true;
            return false;
        }
        return false;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<int> dx = {1,0,-1,0};
        vector<int> dy = {0,1,0,-1};
        queue<pair<int,int>> q;
        q.push(make_pair(entrance[0], entrance[1]));
        q.push(make_pair(INT_MAX, INT_MAX));
        vector<vector<bool>> vis(maze.size()+1, vector<bool> (maze[0].size()+1, false));
        int steps = 0;
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            if(p.first == INT_MAX && p.second == INT_MAX)
            {
                if(q.empty())continue;
                else
                {
                    q.push(make_pair(INT_MAX, INT_MAX));
                    steps++;
                    continue;
                }
            }
            vis[p.first][p.second]=true;
            if(steps!=0 && isexit(p.first, p.second, maze.size(), maze[0].size(), maze)) return steps;
            else
            {
                for(int i=0;i<=3; i++)
                {
                    int xx = p.first+dx[i];
                    int yy = p.second+dy[i];
                    if(checker(xx, yy, maze.size(), maze[0].size()) && !vis[xx][yy] && maze[xx][yy]=='.')
                    {
                        q.push(make_pair(xx,yy));
                        vis[xx][yy]=true;
                    }
                }
            }
        }
        return -1;
    }
};