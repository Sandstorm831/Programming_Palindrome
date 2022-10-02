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
void topologicalSorter(vector<list<int>> graph, int source, vector<bool>& visited, stack<int>& grep)
{
    visited[source] = true;
    list<int> holder = graph[source];
    for(auto itr = holder.begin(); itr!=holder.end(); itr++)
    {
        if(!visited[*itr])
        {
            topologicalSorter(graph, *itr, visited, grep);
        }
    }
    grep.push(source);
}
int main()
{
    vector<pair<int,int>> det;
    det.push_back(make_pair(1,4));
    det.push_back(make_pair(1,3));
    det.push_back(make_pair(3,4));
    det.push_back(make_pair(3,2));
    det.push_back(make_pair(4,2));
    det.push_back(make_pair(2,5));
    det.push_back(make_pair(6,5));
    det.push_back(make_pair(6,2));
    int nodes = 6;
    vector<list<int>> mo = directedgraphcompiler(det, nodes);
    vector<bool> visited(nodes+1, false);
    stack<int> grepper;
    for (int source = 1; source <= nodes; source++)
    {
        if(visited[source] == false) topologicalSorter(mo, source, visited, grepper);
    }
    int n = grepper.size();
    for (int i = 0; i < n; i++)
    {
        cout<<grepper.top()<<" ";
        grepper.pop();
    }
    
}