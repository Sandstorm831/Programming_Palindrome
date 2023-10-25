#include <bits/stdc++.h>
using namespace std;
vector<int> traj;
vector<int> fin;

unordered_map<int,int> ump;
void dfs(vector<vector<int>>& graph, vector<bool>& vis, int node, int dist, vector<bool>& temb)
{
    // cout<<"ehre"<<endl;
    // if(vis[node] && temb[node])
    if(temb[node])
    {
        if(dist - ump[node] > 1) 
        {
            traj.push_back(node);
            for(int j=ump[node]; j<=dist;j++)
            {
                fin.push_back(traj[j]);
            }
            traj.pop_back();
            return;
        }
        return;
    }
    else if(vis[node]) return;
    if(!fin.empty()) return;
    traj.push_back(node);
    ump[node] = dist;
    vis[node] = true;
    temb[node]=true;
    for(int i=0;i<graph[node].size(); i++)
    {
        if( fin.empty())
        {
            dfs(graph, vis, graph[node][i], dist+1, temb);
        }
        else if(!fin.empty()) break;
    }
    traj.pop_back();
    temb[node]=false;
    return;
}
int main()
{
    int n,m;cin>>n>>m;
    vector<vector<int>> graph(n+1, vector<int> ());
    for(int i=0;i <m;i++)
    {
        int x, y;cin>>x>>y;
        graph[x].push_back(y);
    }
    vector<bool> vis(n+1, false);
    vector<bool> temb(n+1, false);
    fin.clear();
    for(int i=1;i<=n  && fin.empty(); i++)
    {
        traj.clear();
        dfs(graph, vis, i, 0, temb);
    }
    if(fin.empty())
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<fin.size()<<endl;
    for(int i=0; i<fin.size(); i++) cout<<fin[i]<<" ";
}