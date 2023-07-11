// Question LInk -https://leetcode.com/problems/is-graph-bipartite/description?envType=study-plan-v2&envId=graph-theory
// Solution 

class Solution {
public:
    bool ans=true;
    void bfs(int node, vector<vector<int>>& graph, vector<int>& colors)
    {
        queue<int> q;
        q.push(node);
        q.push(INT_MAX);
        int curcol=1;
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            if(x==INT_MAX)
            {
                if(q.empty()) continue;
                else
                {
                    q.push(INT_MAX);
                    if(curcol==1) curcol=2;
                    else curcol=1;
                    continue;
                }
            }
            colors[x]=curcol;
            for(int i=0; i<graph[x].size();i++)
            {
                if(colors[graph[x][i]] == curcol && colors[graph[x][i]] != 0) 
                {
                    // cout<<x<<" "<<graph[x][i]<<" "<<endl;
                    ans = false;
                    return;
                }
                else if(colors[graph[x][i]]==0)
                {
                    q.push(graph[x][i]);
                    if(curcol==1)colors[graph[x][i]]=2;
                    else colors[graph[x][i]]=1;
                }
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(), 0);
        for(int i=0;i<graph.size() && ans; i++)
        {
            if(colors[i]==0) bfs(i,graph, colors);
        }
        return ans;
    }
};