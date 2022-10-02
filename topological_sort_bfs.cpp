// Topological sort is only possible for Directed Acyclic Graph;
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
void bfs(vector<list<int>> graph, int nodes, int source, vector<int>& indeg, vector<int>& final)
{
    queue<int> que;
    for (int i = 1; i <= nodes; i++)
    {
        if(indeg[i] == 0) que.push(i);
    }
    while (!que.empty())
    {
        int nakli = que.front();
        final.push_back(nakli);
        que.pop();
        list<int> holder = graph[nakli];
        for (auto it = holder.begin(); it != holder.end() ; it++)
        {
            if(--indeg[*it]==0) que.push(*it);
        }
    }
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
    det.push_back(make_pair(7,8));
    int nodes = 8;
    vector<list<int>> mo = directedgraphcompiler(det, nodes);
    vector<int> indeg(nodes+1,0);
    for (int i = 1; i <= nodes; i++)
    {
        list<int> holder = mo[i];
        for (auto j = holder.begin(); j != holder.end(); j++)
        {
            indeg[*j]++;
        }
    }
    vector<int> final;
    bfs(mo, nodes, 1, indeg, final);
    for (int i = 0; i < final.size(); i++)
    {
        cout<<final[i]<<" ";
    } 
}