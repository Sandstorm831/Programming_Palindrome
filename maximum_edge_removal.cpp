// Question Link - https://www.interviewbit.com/problems/maximum-edge-removal/
// Solution

vector<vector<int>> graph;
vector<bool>vis;
int ans=0;
int dfs(int node)
{
    if(vis[node]) return 0;
    vis[node]=1;
    int nds=1;
    for(int i=0; i<graph[node].size(); i++)
    {
        if(!vis[graph[node][i]])
        {
            int x = dfs(graph[node][i]);
            if(x>=2 && x%2==0) 
            {
                ans++;
                x=0;
            }
            nds += x;
        }
    }
    return nds;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    graph.clear();
    graph.resize(A+1, vector<int> ());
    vis.clear();
    vis.resize(A+1, false);
    ans=0;
    for(int i=0; i<B.size(); i++)
    {
        graph[B[i][0]].push_back(B[i][1]);
        graph[B[i][1]].push_back(B[i][0]);
    }
    int nods = dfs(1);
    return ans;
}
