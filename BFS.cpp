#include <bits/stdc++.h>
using namespace std;
vector<list<int>> directedgraphcompiler(vector<pair<int,int>> det, int nodes)
{
    vector<list<int>> graph(nodes+1);
    for (int i = 0; i < det.size(); i++)
    {
        graph[det[i].first].push_back(det[i].second);
    }
    return graph;
}
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
void bfs(vector<list<int>> graph, int nodes, int source, vector<bool>& visited)
{
    queue<int> que;
    que.push(source);
    visited[source] = true;
    while (!que.empty())
    {
        int nakli = que.front();
        list<int> holder = graph[nakli];
        list<int>::iterator it;
        for ( it = holder.begin(); it != holder.end() ; it++)
        {
            if(visited[*it] == false)
            {
                visited[*it] = true;
                que.push(*it);
            }
        }
        cout<<que.front();
        que.pop();
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
    int nodes = 6;
    vector<list<int>> mo = adirectedgraphcompiler(det, nodes);
    vector<bool> visited(nodes+1, false);
    for (int source = 1; source <= nodes; source++)
    {
        if(visited[source] == false) bfs(mo, nodes, source, visited);
    }
}