#include <bits/stdc++.h>
using namespace std;
vector<list<pair<int,int>>> directedgraphcompiler(vector<pair<pair<int,int>,int>> det, int nodes)
{
    vector<list<pair<int,int>>> graph(nodes+1);
    for (int i = 0; i < det.size(); i++)
    {
        graph[det[i].first.first].push_back(make_pair(det[i].first.second, det[i].second));
    }
    return graph;
}
void recursor(vector<list<pair<int,int>>> graph, vector<bool>& visited, int starter)
{
    visited[starter] = true;
    cout<<starter;
    list<pair<int,int>> holder = graph[starter];
    for (auto it = holder.begin(); it != holder.end(); it++)
    {
        if(visited[it->first] == false)
        {
            recursor(graph, visited, it->first);
        }
    }
}
void dfs(vector<list<pair<int,int>>> graph, int nodes)
{
    vector<bool> visited(nodes+1, false);
    for (int starter = 1; starter < nodes+1; starter++)
    {
        if(visited[starter] == false) recursor(graph, visited, starter);
    }
}
void bfs(vector<list<pair<int,int>>> graph, int nodes, int source, vector<bool>& visited)
{
    queue<int> que;
    que.push(source);
    visited[source] = true;
    while (!que.empty())
    {
        int nakli = que.front();
        list<pair<int,int>> holder = graph[nakli];
        list<pair<int,int>>::iterator it;
        for ( it = holder.begin(); it != holder.end() ; it++)
        {
            if(visited[it->first] == false)
            {
                visited[it->first] = true;
                que.push(it->first);
            }
        }
        cout<<que.front();
        que.pop();
    }
}
int bellmanFord(vector<list<pair<int,int>>> graph, int nodes, int source)
{
    vector<int> distances(nodes+1, INT_MAX);
    distances[source] = 0;  
    for (int i = 1; i < nodes; i++)
    {
        for (int j = 1; j < graph.size(); j++)
        {
            list<pair<int,int>>::iterator itr;
            for(itr = graph[j].begin(); itr != graph[j].end(); itr++)
            {
                if(distances[j] != INT_MAX && distances[itr->first] > distances[j]+itr->second) distances[itr->first] = distances[j]+itr->second;   
            }
        }
    }
    for (int j = 1; j < graph.size(); j++)
    {
        list<pair<int,int>>::iterator itr;
        for(itr = graph[j].begin(); itr != graph[j].end(); itr++)
        {
            if(distances[j] != INT_MAX && distances[itr->first] > distances[j]+itr->second) return 1;   
        }
    }
    return 0;    
}
int main()
{
    vector<pair<pair<int,int>,int>> det;
    det.push_back(make_pair(make_pair(1,2), 3));
    det.push_back(make_pair(make_pair(1,3), 1));
    det.push_back(make_pair(make_pair(2,3), -8));
    det.push_back(make_pair(make_pair(3,4), 2));
    det.push_back(make_pair(make_pair(4,2), 4));
    int nodes = 4, source =1;
    vector<bool> visited(nodes+1, false);
    vector<list<pair<int,int>>> mo = directedgraphcompiler(det, nodes);
    // dfs(mo, nodes);
    // bfs(mo, nodes,source, visited);   
    cout<<bellmanFord(mo, nodes, source);
}