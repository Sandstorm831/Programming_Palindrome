#include <bits/stdc++.h>
using namespace std;
class disjiontSet{
    vector<int> elder;
    vector<int> rank;
    int n;
    public:
    disjiontSet(int a)
    {
        elder.resize(a+1);
        rank.resize(a+1,0);
        n = a;
        setter();
    }
    void setter()
    {
        for (int i = 0; i < n; i++)
        {
            elder[i] = i;
        }
    }
    int find(int x)
    {
        if(elder[x] == x) return elder[x];
        elder[x] = find(elder[x]);
        return elder[x];
    }
    void Union(int x, int y)
    {
        int elder_a = find(x);
        int elder_b = find(y);
        if(elder_a == elder_b) return;
        if(rank[elder_a]>rank[elder_b]) elder[elder_b] = elder_a;
        else if(rank[elder_a]<rank[elder_b]) elder[elder_a] = elder_b;
        else
        {
            elder[elder_a] = elder_b;
            rank[elder_b] += 1;
        }
    }
    void Display()
    {
        for (int i = 0; i < n; i++)
        {
            cout<<elder[i]<<" ";
        }
        cout<<endl;
    }
};
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
vector<pair<int,pair<int,int>>> graphDecompiler(vector<list<pair<int,int>>> graph)
{
    vector<pair<int,pair<int,int>>> retriever;
    list<pair<int,int>>::iterator itr;
    for (int i = 1; i < graph.size(); i++)
    {
        for ( itr = graph[i].begin(); itr != graph[i].end(); itr++)
        {
            retriever.push_back(make_pair(itr->second, make_pair(i,itr->first)));
        }
    }
    return retriever;
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
vector<pair<int,pair<int,int>>> KruskalAlgo(vector<pair<int,pair<int,int>>> edges, int nodes)
{
    vector<pair<int,pair<int,int>>> backer;
    disjiontSet obj(nodes);
    int summ = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        if(obj.find(edges[i].second.first) != obj.find(edges[i].second.second))
        {
            backer.push_back(edges[i]);
            summ += edges[i].first;
            obj.Union(edges[i].second.first, edges[i].second.second);
        }   
    }
    backer.push_back(make_pair(summ, make_pair(summ, summ)));
    return backer;
}
int main()
{
    vector<pair<pair<int,int>,int>> det;
    det.push_back(make_pair(make_pair(1,2), 1));
    det.push_back(make_pair(make_pair(1,5), 5));
    det.push_back(make_pair(make_pair(2,5), 6));
    det.push_back(make_pair(make_pair(2,3), 2));
    det.push_back(make_pair(make_pair(5,3), 4));
    det.push_back(make_pair(make_pair(5,4), 8));
    det.push_back(make_pair(make_pair(3,4), 7));
    int nodes = 5, source =1;
    vector<bool> visited(nodes+1, false);
    vector<list<pair<int,int>>> mo = adirectedgraphcompiler(det, nodes);
    vector<pair<int,pair<int,int>>> back = graphDecompiler(mo);
    sort(back.begin(), back.end());
    // dfs(mo, nodes);
    // bfs(mo, nodes,source, visited);
    vector<pair<int,pair<int,int>>> final = KruskalAlgo(back, nodes);
    for (int i = 0; i < final.size()-1; i++)
    {
        cout<<"i = "<<final[i].second.first<<" | j = "<<final[i].second.second<<" | lenght = "<<final[i].first<<endl;
    }
    cout<<"summ = "<<final.back().first;
}