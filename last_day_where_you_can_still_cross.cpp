// Question Link - https://leetcode.com/problems/last-day-where-you-can-still-cross/description/
// Solution 

class Solution {
public:
    void equalizer(int mid, int prev, vector<vector<int>>& graph, vector<vector<int>>& cells)
    {
        if(mid < prev)
        {
            for(int i=prev; i>mid; i--)
            {
                graph[cells[i][0]-1][cells[i][1]-1] = 0;
            }
        }
        else
        {
            for(int i=prev+1; i<=mid; i++)
            {
                graph[cells[i][0]-1][cells[i][1]-1] = 1;
            }
        }
    }
    int checker(int x, int y, int n, int m)
    {
        if(x>=0 && y>=0 && x<n && y<m) return 1;
        return 0;
    }
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int dfs(vector<vector<int>>& graph, int row, int col, vector<vector<bool>>& vis)
    {
        vis[row][col] = true;
        if(row == graph.size()-1 && graph[row][col]==0) return 1;
        int ans = 0;
        for(int i=0; i<4; i++)
        {
            int xx = row+dx[i];
            int yy = col+dy[i];
            if(checker(xx, yy, graph.size(), graph[0].size()) && !vis[xx][yy] && graph[xx][yy]==0) ans += dfs(graph, xx, yy, vis);
        }
        if(ans > 0) return 1;
        return 0;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> graph(row, vector<int> (col,0));
        int low=0, high = cells.size()-1;
        int prev=0;
        graph[cells[0][0]-1][cells[0][1]-1]=1;
        vector<vector<bool>> vis;
        while(low<high)
        {
            int mid = (low+high)/2;
            equalizer(mid, prev, graph, cells);
            vis.resize(row, vector<bool> (col, false));
            int ans=0;
            for(int i=0; i<col && ans==0; i++)
            {
                if(!vis[0][i] && graph[0][i]==0) ans = dfs(graph, 0,i,vis);
            }
            vis.clear();
            if(ans)
            {
                low=mid+1, 
                prev = mid;
            }
            else
            {
                high = mid-1;
                prev = mid;
            }
        }
        equalizer((low+high)/2, prev, graph, cells);
        vis.clear();
        vis.resize(row, vector<bool> (col, false));
        int ans=0;
        for(int i=0; i<col && ans==0; i++)
        {
            if(!vis[0][i] && graph[0][i]==0) ans = dfs(graph, 0,i,vis);
        }
        if(ans)
        {
            return (((low+high)/2))+1;
        }
        return ((low+high)/2);
    }
};