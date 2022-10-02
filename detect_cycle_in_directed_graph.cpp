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
bool recursor(vector<list<int>> graph, vector<bool>& visited, int source, vector<bool>& recstack)
{
    visited[source] = true;
    recstack[source] = true;
    list<int> holder = graph[source];
    for(auto itr = holder.begin(); itr != holder.end(); itr++)
    {
        if(!visited[*itr])
        {
            if(recursor(graph, visited, *itr, recstack))
            {
                return true;
            }
        }
        else if(recstack[*itr])
        {
            return true;
        }
    }
    recstack[source]=false;
    return false;
}
bool cycleFinder(vector<list<int>> graph, int nodes)
{
    vector<bool> visited(nodes+1, false);
    vector<bool> recstack(nodes+1, false);
    for (int i = 1; i <= nodes; i++)
    {
        if(!visited[i])
        {
            if(recursor(graph, visited, i, recstack)) return true;
        }
    }
    return false;
}
int main()
{
    vector<pair<int,int>> det;
    det.push_back(make_pair(1,2));
    det.push_back(make_pair(2,3));
    det.push_back(make_pair(4,3));
    det.push_back(make_pair(4,1));
    int nodes = 4, source =1;
    vector<list<int>> mo = directedgraphcompiler(det, nodes);
    cout<<cycleFinder(mo, nodes);
}