#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> edg;
vector<int> a, run, looped, visited;
int n, m, flag, curr;
long long k;
int N = 2e5+5;
void dfs(int node)
{
    visited[node] = 1; looped[node]=1;
    for(int j=0; j<edg[node].size(); j++)
    {
        // cout<<edg[node][j]<<" | ";
        if( a[edg[node][j]] > curr) 
        {
            // cout<<endl<<edg[node][j]<<" {} "<<a[edg[node][j]]<<" > "<<curr<<endl;
            continue;
        }
        if(looped[edg[node][j]]) flag=1;
        else
        {
            if(!visited[edg[node][j]]) dfs(edg[node][j]);
            run[node] = max(run[node], run[edg[node][j]]+1);
        }
    }
    looped[node]=0;
}
bool check(int mid)
{
    curr=mid;
    flag=0;
    visited.clear();visited.resize(N,0);
    run.clear();run.resize(N, 0);
    for(int j=1; j<=n; j++)
    {
        if(visited[j]||a[j]>curr) continue;
        dfs(j);
    }
    if(flag) return 1;
    for(int j=1; j<=n; j++) if(run[j]>=k-1) return 1;
    return 0;
}
int main()
{
    cin>>n>>m>>k;
    visited.resize(n+1,0);
    run.resize(n+1, 0);
    looped.resize(n+1, 0);
    edg.resize(n+1, vector<int> ());
    a.resize(n+1);
    int minn=INT_MAX;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        minn = min(minn, a[i]);
    }
    if(k == 1) 
    {
        cout<<minn<<endl;
        return 0;
    }
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        edg[x].push_back(y);
    }
    // for(int j=0; j<edg.size(); j++) for(int i=0; i<edg[j].size(); i++) cout<<edg[j][i]<<" ";
    int l=0;
    int h = 1e9;
    int ans=-1;
    int mid;
    while(l<=h)
    {
        mid = (l+h)>>1;
        if(check(mid)) h=mid-1,ans=mid;
        else l=mid+1;
        // cout<<mid<<" | ";
    }
    cout<<ans<<endl;
    return 0;
}