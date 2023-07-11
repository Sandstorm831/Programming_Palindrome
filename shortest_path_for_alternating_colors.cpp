// Question Link - https://leetcode.com/problems/shortest-path-with-alternating-colors/description/
// Solution 

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> graph(n, vector<pair<int,int>> ());
        for(int i=0; i<redEdges.size(); i++)
        {
            graph[redEdges[i][0]].push_back(make_pair(redEdges[i][1], 1));
            // graph[redEdges[i][1]].push_back(make_pair(redEdges[i][0], 1));
        }
        for(int i=0; i<blueEdges.size(); i++)
        {
            graph[blueEdges[i][0]].push_back(make_pair(blueEdges[i][1], 0));
            // graph[blueEdges[i][1]].push_back(make_pair(blueEdges[i][0], 0));
        }
        vector<vector<bool>> vis(n, vector<bool> (2,false));
        vector<int> dist(n,INT_MAX);
        // vis[0][0]=true;
        dist[0]=0;
        queue<pair<int,int>> q;
        // cout<<graph[0].size()<<endl;
        for(int i=0;i<graph[0].size();i++)
        {
            // if(!vis[graph[0][i].first])
            q.push(make_pair(graph[0][i].first, graph[0][i].second));
            // dist[graph[0][i].first]=1;
        }
        q.push(make_pair(INT_MAX, INT_MAX));
        int curdis=1;
        while(!q.empty())
        {
            pair<int,int> a = q.front();
            q.pop();
            if(a.first == INT_MAX && a.second == INT_MAX)
            {
                if(q.empty()) 
                {
                    // curdis++;
                    continue;
                }
                else q.push(make_pair(INT_MAX, INT_MAX));
                curdis++;
                continue;
            }
            vis[a.first][a.second]=true;
            if(curdis<dist[a.first]) dist[a.first]=curdis;
            if(a.second==1)
            {
                for(int i=0; i<graph[a.first].size();i++)
                {
                    if(!vis[graph[a.first][i].first][graph[a.first][i].second] && graph[a.first][i].second==0)
                    {
                        q.push(make_pair(graph[a.first][i].first, 0));
                    }
                }
            }
            else if(a.second==0)
            {
                for(int i=0; i<graph[a.first].size();i++)
                {
                    if(!vis[graph[a.first][i].first][graph[a.first][i].second] && graph[a.first][i].second==1)
                    {
                        q.push(make_pair(graph[a.first][i].first, 1));
                    }
                }
            }            
        }
        for(int i=0; i<dist.size();i++)
        {
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
        return dist;
    }
};