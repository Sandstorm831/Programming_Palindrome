#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> visited;
vector<int> ahd;
vector<vector<int>> ngraph;
int dfs(int node, int parent)
{
    if(graph[node].size() == 1) 
    {
        ngraph[parent].push_back(node);
        ahd[node]=0;
        return 1;
    }
    if(visited[node]==1) 
    {
        return 0;
    }
    visited[node]=1;
    if(parent!=-1) ngraph[parent].push_back(node);
    int count=0;
    for(int i=0; i<graph[node].size(); i++)
    {
        count+=dfs(graph[node][i], node);
    }
    ahd[node]=count;
    return count+1;
}
int recursor(int node)
{
    if(ngraph[node].size()==0) return 0;
    else if(ngraph[node].size()==1) return ahd[node]-1;
    else
    {
        int x = ahd[ngraph[node][0]]+recursor(ngraph[node][1]);
        int y = ahd[ngraph[node][1]]+recursor(ngraph[node][0]);
        return max(x,y);
    }
}
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases;i++)
    {
        int n;
        cin>>n;
        graph.clear();
        graph.resize(n+1, vector<int> ());
        for(int j=1;j<=n-1; j++)
        {
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        if(graph[1].size()==1) 
        {
            cout<<max(n-2,0)<<endl;
            continue;
        }
        visited.clear();
        visited.resize(n+1, 0);
        ahd.clear();
        ahd.resize(n+1,0);
        ngraph.clear();
        ngraph.resize(n+1, vector<int> ());
        int x = dfs(1,-1);
        int ans = recursor(1);
        cout<<ans<<endl;
    }
}