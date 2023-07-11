// Question Link - https://leetcode.com/problems/find-eventual-safe-states/description/?envType=study-plan-v2&envId=graph-theory
// solution 

class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& ans, vector<bool>& cur, int node)
    {
        if(cur[node]) return false;
        if(vis[node]) return ans[node];
        vis[node]=true;
        cur[node]=true;
        bool curc=true;
        for(int i=0; i<graph[node].size(); i++)
        {
            // cout<<node<<" "<<graph[node][i]<<endl;
            if(!dfs(graph, vis, ans, cur, graph[node][i]))
            {
                // cout<<"here"<<endl;
                curc=false;
                break;
            }
        }
        // cout<<node<<curc<<
        cur[node]=false;
        if(!curc) ans[node]=false;
        return curc;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, false);
        vector<bool> ans(n, true);
        vector<bool> cur(n, false);
        for(int i=0;i<n;i++)
        {
            dfs(graph, vis, ans,cur, i);
        }
        vector<int> v;
        for(int i=0;i<n; i++)
        {
            // cout<<ans[i]<<" ";
            if(ans[i]) v.push_back(i);
        }
        return v;
    }
};