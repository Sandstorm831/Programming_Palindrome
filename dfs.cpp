#include <bits/stdc++.h>
using namespace std;
vector<list<int>> adirectedgraphcompiler(vector<pair<int,int>> det, int nodes)
{
    vector<list<int>> graph(nodes+1);
    for (int i = 0; i < det.size(); i++)
    {
        graph[det[i].first].push_back(det[i].second);
        graph[det[i].second].push_back(det[i].first);
    }
    return graph;
}
void recursor(vector<list<int>> graph, vector<bool>& visited, int starter)
{
    visited[starter] = true;
    cout<<starter;
    list<int> holder = graph[starter];
    for (auto it = holder.begin(); it != holder.end(); it++)
    {
        if(visited[*it] == false)
        {
            recursor(graph, visited, *it);
        }
    }
}
void dfs(vector<list<int>> graph, int nodes)
{
    vector<bool> visited(nodes+1, false);
    for (int starter = 1; starter < nodes+1; starter++)
    {
        if(visited[starter] == false) recursor(graph, visited, starter);
    }
}
int main()
{
    vector<pair<int,int>> det;
    det.push_back(make_pair(1,2));
    det.push_back(make_pair(1,5));
    det.push_back(make_pair(1,3));
    det.push_back(make_pair(2,5));
    det.push_back(make_pair(5,4));
    det.push_back(make_pair(5,6));
    det.push_back(make_pair(3,4));
    det.push_back(make_pair(4,6));
    int nodes = 6, source =1;
    vector<list<int>> mo = adirectedgraphcompiler(det, nodes);
    dfs(mo, nodes);
}