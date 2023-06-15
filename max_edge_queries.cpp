// Question LInk - https://www.interviewbit.com/problems/max-edge-queries/
// solution

void dfs(vector<vector<pair<int,int>>> &graph, int node, int log, vector<bool> &vis, vector<vector<int>> &lc, vector<vector<int>> &mx, vector<int>& levels, int curlevel)
{
    if(vis[node]) return;
    vis[node]=true;
    levels[node] = curlevel;
    for(int i=0; i<graph[node].size(); i++)
    {
        if(!vis[graph[node][i].first])
        {
            lc[graph[node][i].first][0] = node;
            mx[graph[node][i].first][0] = graph[node][i].second;
        }
    }
    for(int i=0; i<graph[node].size(); i++)
    {
        for(int j=1; j<=log; j++)
        {
            if(!vis[graph[node][i].first])
            {
                lc[graph[node][i].first][j] = lc[lc[graph[node][i].first][j-1]][j-1];
                mx[graph[node][i].first][j] = max(mx[graph[node][i].first][j-1], mx[lc[graph[node][i].first][j-1]][j-1]);
            }
        }
    }
    for(int i=0; i<graph[node].size(); i++)
    {
        if(!vis[graph[node][i].first])
        {
            dfs(graph, graph[node][i].first, log, vis, lc, mx, levels, curlevel+1);
        }
    }
    return;
}
int finder(int a, int b, vector<vector<pair<int,int>>> &graph, int log, vector<vector<int>> &lc, vector<vector<int>> &mx, vector<int>& levels)
{
    // cout<<a<<" "<<levels[a]<<" | "<<b<<" "<<levels[b]<<endl;
    if(levels[a]<levels[b]) swap(a,b);
    int d = levels[a]-levels[b];
    int res=-1;
    for(int i=log; i>=0; i--)
    {
        if(levels[a]-pow(2,i) >= levels[b])
        {
            res = max(res, mx[a][i]);
            a = lc[a][i];
        }
    }
    // cout<<a<<" "<<mx[a][0]<<" | "<<b<<" "<<mx[b][0]<<endl;
    if(b==a) return res;
    for(int i=log; i>=0; i--)
    {
        if(lc[a][i] != lc[b][i])
        {
            // cout<<" a="<<a<<" "<<lc[a][i]<<" & b="<<b<<" "<<lc[b][i]<<endl;
            res = max(res, mx[a][i]);
            res = max(res, mx[b][i]);
            a = lc[a][i];
            b = lc[b][i];
        }
    }
    // cout<<a<<" "<<mx[a][0]<<" | "<<b<<" "<<mx[b][0]<<endl;
    res = max(res, mx[a][0]);
    res = max(res, mx[b][0]);
    return res;
}
vector<int> Solution::solve(vector<vector<int> > &A, vector<vector<int> > &B) {
    int n = A.size()+1;
    vector<vector<pair<int,int>>> graph(n+1, vector<pair<int,int>> ());
    for(int i=0;i<A.size(); i++)
    {
        graph[A[i][0]].push_back(make_pair(A[i][1], A[i][2]));
        graph[A[i][1]].push_back(make_pair(A[i][0], A[i][2]));
    }
    int log = (int)ceil(log2(n));
    vector<vector<int>> lc(n+1, vector<int> (log+1, 0)),mx(n+1, vector<int> (log+1,0));
    vector<int> levels(n+1, 0);
    vector<bool> vis(n+1, false);
    dfs(graph, 1, log, vis, lc, mx, levels, 0);
    vector<int> ans;
    for(int i=0;i<B.size(); i++)
    {
        ans.push_back(finder(B[i][0], B[i][1], graph, log, lc,mx,levels));
    }
    return ans;
}
// To Understand
// https://www.geeksforgeeks.org/lca-in-a-tree-using-binary-lifting-technique/
// https://youtu.be/dOAxrhAUIhA
// https://www.youtube.com/watch?v=oib-XsjFa-M&t=868s