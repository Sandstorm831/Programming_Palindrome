// QUestion Link - https://leetcode.com/problems/course-schedule/description/?envType=study-plan-v2&envId=graph-theory
// Solution  

class Solution {
public:
    bool ans;
    void dfs(int node, int par, vector<bool>& vis, vector<vector<int>>& graph, vector<bool> jus)
    {
        vis[node] = true;
        jus[node]=true;
        for(int i=0; i<graph[node].size(); i++)
        {
            if(!vis[graph[node][i]])
            {
                dfs(graph[node][i], node, vis, graph, jus);
            }
            else if(jus[graph[node][i]])
            {
                ans=true;
                return;
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        ans=false;
        vector<bool> vis(numCourses,false);
        vector<vector<int>> graph(numCourses, vector<int> ());
        for(int i=0; i<prerequisites.size(); i++)
        {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses; i++)
        {
            vector<bool> jus(numCourses, false);
            if(!vis[i]) dfs(i,-1,vis, graph, jus);
            if(ans) return false;
        }
        return true;
    }
};