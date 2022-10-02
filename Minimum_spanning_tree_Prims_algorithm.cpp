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
int primsAlgorithm(vector<list<pair<int,int>>> graph, vector<bool>& visited, int source)
{
    int summ = 0;
    list<pair<int,int>> holder  = {{source, 0}};
    while (!holder.empty())
    {
        int mine = INT_MAX, mine_l = INT_MAX; list<pair<int,int>>::iterator it;
        for (auto itr = holder.begin(); itr !=holder.end(); itr++)
        {
            if(mine_l > itr->second && !visited[itr->first])
            {
                mine_l = itr->second;
                mine = itr->first;
                it = itr;
            }
        }
        if(mine_l == INT_MAX) break;
        visited[mine] = true;
        holder.erase(it);
        summ += mine_l;
        holder.merge(graph[mine]);
    }
    return summ;
}
int main()
{
    vector<pair<pair<int,int>,int>> det;
    det.push_back(make_pair(make_pair(1,2), 2));
    det.push_back(make_pair(make_pair(1,4), 3));
    det.push_back(make_pair(make_pair(1,7), 4));
    det.push_back(make_pair(make_pair(2,3), 3));
    det.push_back(make_pair(make_pair(2,5), 2));
    det.push_back(make_pair(make_pair(4,5), 5));
    det.push_back(make_pair(make_pair(5,6), 7));
    det.push_back(make_pair(make_pair(5,7), 6));
    det.push_back(make_pair(make_pair(5,7), 6));
    int nodes = 7, source =1;
    vector<bool> visited(nodes+1, false);
    vector<list<pair<int,int>>> mo = adirectedgraphcompiler(det, nodes);
    // dfs(mo, nodes);
    // bfs(mo, nodes,source, visited);
    cout<<primsAlgorithm(mo, visited, 1);
}