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
void bfs(vector<list<int>> graph, int nodes, int source)
{
    queue<int> que;
    vector<bool> visited(nodes+1, false);
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
int shortDist(vector<list<int>> graph, int nodes, int source, int dest)
{
    vector<int> dist(nodes+1);
    queue<int> que;
    que.push(source);
    que.push(INT_MAX);
    vector<bool> visited(nodes+1);
    for (int i = 0; i <= nodes; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
    }
    int dista = 0;
    dist[source] = 0;
    visited[source] = true;
    dista++;
    while(!que.empty())
    {
        if(que.front() == INT_MAX)
        {
            dista++;
            que.pop();
            continue;
        }
        int tempro = que.front();
        list<int> holder = graph[tempro];
        list<int>::iterator it;
        for ( it = holder.begin(); it != holder.end(); it++)
        {
            if(visited[*it] == false)
            {
                dist[*it] = dista;
                visited[*it] = true;
                que.push(*it);
            }
        }
        que.pop();
        if(que.front() == INT_MAX) que.push(INT_MAX);
    }
    for (int i = 1; i < dist.size(); i++)
    {
        cout<<"||"<<dist[i]<<"||";
    }
    cout<<endl;
    return dist[dest];
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
    det.push_back(make_pair(6,7));    
    int nodes = 7, source = 1, dest = 7;
    vector<list<int>> graph = adirectedgraphcompiler(det, nodes);
    cout<<shortDist(graph, nodes, source, dest);
}