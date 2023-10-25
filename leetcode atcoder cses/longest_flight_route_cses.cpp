/* DP solution, completely correct, but don't know why It doesn't get accepted
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> dp;
vector<bool> vis;
vector<int> chd;
int dfs(int node)
{
    if(vis[node]) return dp[node];
    if(node == graph.size()-1) return 0;
    if(graph[node].size() == 0) return INT_MIN;
    vis[node] = true;
    int counter=INT_MIN;
    int c=-1;
    for(int i=0; i<graph[node].size(); i++)
    {
        if(!vis[graph[node][i]])
        {
            int xx = 1+dfs(graph[node][i]);
            if(xx > counter)
            {
                counter = xx;
                c = graph[node][i];
            }
        }
        else
        {
            int xx = 1+dp[graph[node][i]];
            if(xx > counter)
            {
                counter = xx;
                c = graph[node][i];
            }
        }
    }
    if(counter == INT_MIN) 
    {
        dp[node] = -1;
        chd[node] = -1;
    }
    else 
    {
        dp[node] = counter;
        chd[node] = c;
    }
    return counter;
}
int main()
{
    int n,m;cin>>n>>m;
    graph.clear(), graph.resize(n+1, vector<int>());
    for(int i=0; i<m; i++)
    {
        int x,y;cin>>x>>y;
        graph[x].push_back(y);
    }
    dp.clear(), dp.resize(n+1,-1);
    chd.clear(), chd.resize(n+1,-1);
    vis.clear(),vis.resize(n+1, false);
    dp[n] = 0;
    int x = dfs(1);
    if(dp[1] == -1)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<dp[1]+1<<endl;
    int xx = 1;
    while(xx != n)
    {
        cout<<xx<<" ";
        xx = chd[xx];
    }
    cout<<xx<<endl;
}

*/
// Topological sort solution, 
#include <bits/stdc++.h>
using namespace std; 
void toposort(vector<vector<int>>& graph, vector<int>& inedge, vector<int>& parent, queue<int>& q)
{
    while(!q.empty())
    {    
        int node = q.front();q.pop();
        for(int i=0; i<graph[node].size(); i++)
        {
            inedge[graph[node][i]]--;
            if(inedge[graph[node][i]]==0)
            {
                parent[graph[node][i]] = node;
                if(graph[node][i] != 1) q.push(graph[node][i]);
            }
        }
    }
}
int main()
{
    int n,m;cin>>n>>m;
    vector<vector<int>> graph(n+1, vector<int> ());
    vector<int> inedge(n+1, 0), parent(n+1, -1);
    for(int i=0; i<m;i++)
    {
        int x,y;cin>>x>>y;
        graph[x].push_back(y);
        inedge[y]++;
    }
    queue<int> q;
    for(int i=2; i<=n; i++) if(inedge[i]==0) q.push(i);
    toposort(graph, inedge, parent, q);
    q.push(1);
    parent[n] = -1;
    parent[1] = -1;
    toposort(graph, inedge, parent, q);
    if(parent[n] == -1) cout<<"IMPOSSIBLE"<<endl;
    else
    {
        vector<int> ans;
        int curr = n;
        while(parent[curr] != -1)
        {
            ans.push_back(curr);curr = parent[curr];
        }
        ans.push_back(1);
        cout<<ans.size()<<endl;
        for(int i=ans.size()-1; i>=0; i--) cout<<ans[i]<<" ";
    }
}
// for understanding https://codeforces.com/blog/entry/85246