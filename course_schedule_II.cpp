//Question Link - https://leetcode.com/problems/course-schedule-ii/description/?envType=study-plan-v2&envId=graph-theory
// Solution 

class Solution {
public:
    bool ans;
    void dfs(int node, int par, vector<bool>& vis, vector<vector<int>>& graph, vector<bool> jus, stack<int>& s)
    {
        vis[node] = true;
        jus[node]=true;
        for(int i=0; i<graph[node].size(); i++)
        {
            if(!vis[graph[node][i]])
            {
                dfs(graph[node][i], node, vis, graph, jus, s);
            }
            else if(jus[graph[node][i]])
            {
                ans=true;
                return;
            }
        }
        s.push(node);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        ans=false;
        stack<int> s;
        vector<bool> vis(numCourses,false);
        vector<vector<int>> graph(numCourses, vector<int> ());
        for(int i=0; i<prerequisites.size(); i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> v;
        for(int i=0;i<numCourses; i++)
        {
            vector<bool> jus(numCourses, false);
            if(!vis[i]) dfs(i,-1,vis, graph, jus,s);
            if(ans) return v;
        }
        while(!s.empty())
        {
            int x = s.top();
            v.push_back(x);
            s.pop();
        }
        return v;
    }
};