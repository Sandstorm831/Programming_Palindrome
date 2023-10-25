#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;cin>>n>>m;
    vector<vector<int>> graph(n+1, vector<int> ());
    for(int i=0; i<m; i++)
    {
        int x,y;cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<int> teams(n+1, -1);
    vector<bool> vis(n+1, false);
    bool dum=true;
    for(int j=1; j<=n;j++)
    {
        if(!vis[j])
        {
            queue<int> q;
            q.push(j);
            q.push(INT_MAX);
            int curr;
            if(teams[j] != -1)
            {
                if(teams[j] == 1) curr = 2;
                else if(teams[j] == 2) curr = 1;
            }
            else{
                teams[j]=1;
                curr = 2;
            }
            dum = true;
            while(!q.empty() && dum)
            {
                // cout<<"s"<<endl;
                int x = q.front(); q.pop();
                if(x == INT_MAX)
                {
                    if(q.empty()) continue;
                    q.push(INT_MAX);
                    if(curr == 1) curr=2;
                    else if(curr == 2) curr = 1;
                    continue;
                }
                vis[x] = true;
                for(int i=0;i<graph[x].size();i++)
                {
                    // cout<<"d"<<endl;

                    if(teams[graph[x][i]] != -1 && teams[graph[x][i]] != curr)
                    {
                        dum = false;
                        break;
                    }
                    if(!vis[graph[x][i]])
                    {
                        teams[graph[x][i]] = curr;
                        q.push(graph[x][i]);
                        vis[graph[x][i]]=true;
                    }
                }
            }
            if(!dum) break;
        }
    }
    if(!dum) cout<<"IMPOSSIBLE";
    else for(int i=1; i<teams.size();i++) cout<<teams[i]<<" ";
    cout<<endl;

}