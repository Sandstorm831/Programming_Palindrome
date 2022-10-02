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
bool recursor(vector<list<int>> graph, vector<bool>& visited, int source, int parent)
{
    visited[source] = true;
    list<int> holder = graph[source];
    for(auto itr = holder.begin(); itr != holder.end(); itr++)
    {
        if(visited[*itr] == false) if(recursor(graph, visited, *itr, source)) return true;
        else if(*itr != parent) return true;
    }
    return false;
}
bool cycleFinder(vector<list<int>> graph, int nodes)
{
    vector<bool> visited(nodes+1, false);
    for (int i = 1; i <= nodes; i++)
    {
        if(visited[i] == false) if(recursor(graph, visited, i, -1)) return true;
    }
    return false;
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
    cout<<cycleFinder(mo, nodes);
}