#include <bits/stdc++.h>
using namespace std;
vector<list<pair<int,int>>> adirectedgraphcompiler(vector<pair<pair<int,int>,int>> det, int nodes)
{
    vector<list<pair<int,int>>> graph(nodes+1);
    for (int i = 0; i < det.size(); i++)
    {
        graph[det[i].first.first].push_back(make_pair(det[i].first.second, det[i].second));
        graph[det[i].first.second].push_back(make_pair(det[i].first.first, det[i].second));
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
vector<int> DijkstrasAlgorithm(vector<list<pair<int,int>>> graph,int nodes, vector<bool>& visited, int source)
{
    vector<int> distances(nodes+1, INT_MAX);
    int dist = INT_MAX;
    int min_dist = 0;
    distances[source] = 0;
    list<pair<int, int>> holder = {{source,0}};
    visited[source] = true;
    while(!holder.empty())
    {
        holder = graph[source];
        list<pair<int,int>>::iterator it;
        for(auto itr=holder.begin(); itr!=holder.end();itr++)
        {
            if(!visited[itr->first])
            {
                if(distances[itr->first]>(min_dist+itr->second))
                {
                    distances[itr->first] = min_dist+itr->second;
                }
                if(dist>(min_dist+itr->second))
                {
                    dist = min_dist+itr->second;
                    it = itr;
                }
            }
        }
        if(dist == INT_MAX) break;
        min_dist = dist;
        dist = INT_MAX;
        source = it->first;
        for(int i =1; i<=nodes; i++)
        {
            if(distances[i]<min_dist&&!visited[i])
            {
                source = i;
                min_dist = distances[i];
            }
        }
        visited[source] = true;
    }
    return distances;
}
int main()
{
    vector<pair<pair<int,int>,int>> det;
    det.push_back(make_pair(make_pair(1,4), 2));
    det.push_back(make_pair(make_pair(1,3), 4));
    det.push_back(make_pair(make_pair(4,3), 3));
    det.push_back(make_pair(make_pair(4,6), 1));
    det.push_back(make_pair(make_pair(3,6), 1));
    det.push_back(make_pair(make_pair(5,6), 2));
    det.push_back(make_pair(make_pair(3,2), 9));
    det.push_back(make_pair(make_pair(2,5), 1));
    int nodes = 6, source =1;
    vector<bool> visited(nodes+1, false);
    vector<list<pair<int,int>>> mo = adirectedgraphcompiler(det, nodes);
    // dfs(mo, nodes);
    // bfs(mo, nodes,source, visited);
    vector<int> dijk = DijkstrasAlgorithm(mo,nodes, visited, 1);
    for (int i = 1; i < dijk.size(); i++)
    {
        cout<<dijk[i]<<" ";
    }   
}