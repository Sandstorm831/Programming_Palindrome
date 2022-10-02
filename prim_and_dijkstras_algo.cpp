#include <bits/stdc++.h>
using namespace std;
void adirectedgraphcompiler(vector<vector<pair<int,int>>>& graph, int nodes){
    graph.resize(nodes+1);
    graph[1].push_back(make_pair(2,4));
    graph[2].push_back(make_pair(1,4));
    graph[1].push_back(make_pair(8,8));
    graph[8].push_back(make_pair(1,8));
    graph[2].push_back(make_pair(3,8));
    graph[3].push_back(make_pair(2,8));
    graph[8].push_back(make_pair(2,11));
    graph[2].push_back(make_pair(8,11));
    graph[3].push_back(make_pair(4,7));
    graph[4].push_back(make_pair(3,7));
    graph[3].push_back(make_pair(9,2));
    graph[9].push_back(make_pair(3,2));
    graph[3].push_back(make_pair(6,4));
    graph[6].push_back(make_pair(3,4));
    graph[4].push_back(make_pair(5,9));
    graph[5].push_back(make_pair(4,9));
    graph[4].push_back(make_pair(6,14));
    graph[6].push_back(make_pair(4,14));
    graph[5].push_back(make_pair(6,10));
    graph[6].push_back(make_pair(5,10));
    graph[6].push_back(make_pair(7,2));
    graph[7].push_back(make_pair(6,2));
    graph[7].push_back(make_pair(8,1));
    graph[8].push_back(make_pair(7,1));
    graph[7].push_back(make_pair(9,6));
    graph[9].push_back(make_pair(7,6));
    graph[8].push_back(make_pair(9,7));
    graph[9].push_back(make_pair(8,7));
}
vector<int> primMST(vector<vector<pair<int,int>>> graph, int nodes, int source)
{
/*
1) Initialize keys of all vertices as infinite and 
   parent of every vertex as -1.

2) Create an empty priority_queue pq.  Every item
   of pq is a pair (weight, vertex). Weight (or 
   key) is used  as first item  of pair
   as first item is by default used to compare
   two pairs.

3) Initialize all vertices as not part of MST yet.
   We use boolean array inMST[] for this purpose.
   This array is required to make sure that an already
   considered vertex is not included in pq again. This
   is where Prim's implementation differs from Dijkstra.
   In Dijkstra's algorithm, we didn't need this array as
   distances always increase. We require this array here 
   because key value of a processed vertex may decrease
   if not checked.

4) Insert source vertex into pq and make its key as 0.

5) While either pq doesn't become empty 
    a) Extract minimum key vertex from pq. 
       Let the extracted vertex be u.

    b) Include u in MST using inMST[u] = true.

    c) Loop through all adjacent of u and do 
       following for every vertex v.

           // If weight of edge (u,v) is smaller than
           // key of v and v is not already in MST
           If inMST[v] = false && key[v] > weight(u, v)

               (i) Update key of v, i.e., do
                     key[v] = weight(u, v)
               (ii) Insert v into the pq 
               (iv) parent[v] = u
               
6) Print MST edges using parent array.
*/
    vector<int> store(nodes+1, INT_MAX);
    vector<int> parent(nodes+1, -1);
    vector<bool> visited(nodes+1, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, source));
    store[source]=0;
    while(!pq.empty())
    {
        pair<int,int> idx = pq.top();
        pq.pop();
        if(visited[idx.second]==true) continue;
        visited[idx.second]=true;
        for(auto i=0; i<graph[idx.second].size(); i++)
        {
            if(!visited[graph[idx.second][i].first] && store[graph[idx.second][i].first] > graph[idx.second][i].second)
            {
                store[graph[idx .second][i].first] = graph[idx.second][i].second;
                pq.push(make_pair(graph[idx.second][i].second, graph[idx.second][i].first));
                parent[graph[idx.second][i].first] = idx.second;
            }
        }
    }
    // int sum=0;
    // for (int i = 1; i < store.size(); i++)
    // {
    //     sum+=store[i];   
    // }
    // parent[1]=sum;
    return parent;
}   
vector<int> dijkstra(vector<vector<pair<int,int>>> graph, int nodes, int source)
{
/*
1) Initialize distances of all vertices as infinite.

2) Create an empty priority_queue pq.  Every item
   of pq is a pair (weight, vertex). Weight (or 
   distance) is used  as first item  of pair
   as first item is by default used to compare
   two pairs

3) Insert source vertex into pq and make its
   distance as 0.

4) While either pq doesn't become empty
    a) Extract minimum distance vertex from pq. 
       Let the extracted vertex be u.
    b) Loop through all adjacent of u and do 
       following for every vertex v.

           // If there is a shorter path to v
           // through u. 
           If dist[v] > dist[u] + weight(u, v)

               (i) Update distance of v, i.e., do
                     dist[v] = dist[u] + weight(u, v)
               (ii) Insert v into the pq (Even if v is
                    already there)
               
5) Print distance array dist[] to print all shortest
   paths. 
*/
    vector<int> dist(nodes+1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0,source));
    dist[source]=0;
    while(!pq.empty())
    {
        pair<int,int> idx = pq.top();
        pq.pop();
        for(int i=0; i<graph[idx.second].size(); i++)
        {
            if(dist[graph[idx.second][i].first]>dist[idx.second]+graph[idx.second][i].second)
            {
                dist[graph[idx.second][i].first] = dist[idx.second]+graph[idx.second][i].second;
                pq.push(make_pair(graph[idx.second][i].second, graph[idx.second][i].first));
            }
        }
    }
    return dist;
}
int main()
{
    vector<vector<pair<int,int>>> graph;
    int nodes = 9;
    adirectedgraphcompiler(graph, nodes);
    vector<int> hell = primMST(graph, nodes, 1);
    for (int i = 2; i <= nodes; ++i)
    {
        printf("%d - %d\n", hell[i], i);
    }
    vector<int> dhell = dijkstra(graph, nodes, 1);
    cout<<"***********************************"<<endl;
    for (int i = 1; i < nodes; ++i)
    {
        printf("%d %d\n", i, dhell[i]);
    }
}