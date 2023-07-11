// Question LInk - https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/description/
// Solution

class Solution {
public:
    bool ans ;
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
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0; i<group.size(); i++)
        {
            if(group[i]==-1) group[i] = m++;
        }
        vector<vector<int>> group_graph(m, vector<int>());
        vector<vector<int>> node_graph(n, vector<int>());
        vector<vector<int>> alter(m, vector<int> ());
        for(int i=0;i<group.size(); i++)
        {
            alter[group[i]].push_back(i);
        }
        for(int i=0; i<beforeItems.size();i++)
        {
            for(int j=0; j<beforeItems[i].size(); j++)
            {
                if(group[i] != group[beforeItems[i][j]]) group_graph[group[beforeItems[i][j]]].push_back(group[i]);
                else if(group[i] == group[beforeItems[i][j]]) node_graph[beforeItems[i][j]].push_back(i);
            }
        }
        stack<int> s1,s2;
        ans=false;
        vector<bool> vis(m, false);
        vector<int> v;
        for(int i=0;i<group_graph.size(); i++)
        {
            vector<bool> jus(m, false);
            if(!vis[i]) dfs(i,-1, vis,group_graph, jus, s1);
            if(ans) return v;
        }
        ans=false;
        vis.clear();
        vis.resize(n, false);
        for(int i=0;i<node_graph.size();i++)
        {
            vector<bool> jus(n, false);
            if(!vis[i]) dfs(i, -1, vis, node_graph, jus, s2);
            if(ans) return v;
        }
        vector<bool> gvis(m, false);
        vector<bool> nvis(n, false);
        vector<vector<int>> nodal_top(m, vector<int> ());
        while(!s2.empty())
        {
            int x = s2.top();
            s2.pop();
            nodal_top[group[x]].push_back(x);
        }
        while(!s1.empty())
        {
            int grp = s1.top();
            s1.pop();
            gvis[grp]=true;
            for(int i=0; i<nodal_top[grp].size(); i++)
            {
                if(group[nodal_top[grp][i]] == grp)
                {
                    v.push_back(nodal_top[grp][i]);
                    nvis[nodal_top[grp][i]]=true;
                }
            }
            for(int i=0; i<alter[grp].size();i++)
            {
                if(!nvis[alter[grp][i]])
                {
                    v.push_back(alter[grp][i]);
                    nvis[alter[grp][i]]=true;
                }
            }
        }
        for(int i=0; i<m; i++)
        {
            if(!gvis[i])
            {
                gvis[i] = true;
                for(int j=0; j<alter[i].size(); j++)
                {
                    if(!nvis[alter[i][j]])
                    {
                        v.push_back(alter[i][j]);
                        nvis[alter[i][j]]=true;
                    }
                }
            }
        }
        return v;
    }
};