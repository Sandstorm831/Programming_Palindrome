#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;cin>>n>>m;
    vector<vector<int>>graph(n+1, vector<int> ());
    for(int i=0;i<m; i++)
    {
        int x,y;cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<bool> vis(n+1, false);
    vector<int> dp(n+1, 0);
    dp[1] = 0;
    queue<int> q;
    q.push(1);
    q.push(INT_MAX);
    int counter=0;
    while(!q.empty())
    {
        int node = q.front(); q.pop();
        if(node == INT_MAX)
        {
            if(q.empty()) continue;
            q.push(INT_MAX);
            counter++;
            continue;
        }
        vis[node] = true;
        if(node == n)
        {
            int ns = n;
            vector<int> holder;
            while(ns != 0)
            {
                holder.push_back(ns);
                ns = dp[ns];
            }
            cout<<holder.size()<<endl;
            for(int i=holder.size()-1; i>=0; i--) cout<<holder[i]<<" ";
            return 0;
        }
        for(int i=0; i<graph[node].size(); i++)
        {
            if(!vis[graph[node][i]])
            {
                dp[graph[node][i]] = node;
                vis[graph[node][i]] = true;
                q.push(graph[node][i]);
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}