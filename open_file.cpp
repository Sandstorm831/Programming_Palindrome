#include <bits/stdc++.h>
using namespace std;
// int knapsacktopdown(vector<int> w, vector<int> val, int hold)
// {
//     int size = w.size();
//     vector<vector<int>> dp(size+1, vector<int> (hold+1));
//     for (int i = 0; i <= size; i++)
//     {
//         for (int j = 0; j <= hold; j++)
//         {
//             if(i ==0 || j==0) dp[i][j]=0;
//             else if(j>=w[i-1]) dp[i][j] = max(val[i-1]+dp[i-1][j-w[i-1]], dp[i-1][j]);
//             else dp[i][j] = dp[i-1][j];
//         }
//     }
//     return dp[size][hold];
    
// }
// int longestsubseq(string A, string B)
// {
//     int sizea = A.size();
//     int sizeb = B.size();
//     vector<vector<int>> dp(sizea+1, vector<int> (sizeb+1));
//     for(int i=0; i<=sizea; i++)
//     {
//         for(int j=0; j<=sizeb; j++)
//         {
//             if(i == 0 || j == 0) dp[i][j] = 0;
//             else if(A[i-1] == B[j-1]) dp[i][j] = 1+dp[i-1][j-1];
//             else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//         }
//     }
//     return dp[sizea][sizeb];
// }
// int recursor(vector<int> A, int i, int j, vector<vector<int>>& dp)
// {
//     if(i>=j) return 0;
//     if(dp[i][j] != -1) return dp[i][j];
//     int minn = INT_MAX;
//     for(int k=i; k<=j-1; k++)
//     {
//         int tempo = recursor(A, i, k, dp) + recursor(A, k+1, j, dp) + A[i-1]*A[k]*A[j];
//         minn = min(tempo, minn);
//     }
//     return dp[i][j] = minn;
// }
// int mcm(vector<int> A)
// {
//     int size = A.size();
//     int i=1;
//     int j=size-1;
//     vector<vector<int>> dp(size+1, vector<int> (size+1, -1));
//     return recursor(A, i, j, dp);
// }
// unordered_map<string, vector<string>> dp; 
// vector<string> recursor(unordered_set<string> finder, string culprit, int starter, int size)
// {
//     vector<string> sentences;
//     // string s = to_string(starter);
//     if(culprit.size() == 0) return sentences;
//     // if(dp.find(s) != dp.end()) return dp[s];
//     for(int i=0; i<size; i++)
//     {
//         string a = culprit.substr(starter, i);
//         if(finder.find(a) != finder.end())
//         {
//             vector<string> ret = recursor(finder, culprit, i, size-a.size());
//             for(int j=0; j<ret.size(); j++)
//             {
//                 sentences.push_back(a+" "+ret[j]);
//             }
//         }
//     }
//     return sentences;//dp[s] = 
// }
vector<list<int>> directedgraphcompiler(vector<pair<int,int>> det, int nodes)
{
    vector<list<int>> graph(nodes+1);
    for (int i = 0; i < det.size(); i++)
    {
        graph[det[i].first].push_back(det[i].second);
    }
    return graph;
}
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
void bfs(vector<list<int>> graph, int nodes, int source, vector<bool>& visited)
{
    visited[source] = true;
    queue<int> q;
    q.push(source);
    while(!q.empty())
    {
        int src = q.front();
        for(list<int>::iterator itr = graph[source].begin(); itr!=graph[source].end(); itr++)
        {
            if(!visited[*itr])
            {
                visited[*itr]=true;
                q.push(*itr);
            }
        }
        cout<<q.front();
        q.pop();
    }
}
void dfs(vector<list<int>> graph, int nodes, int source, vector<bool>& visited)
{
    visited[source] = true;
    cout<<source;
    for(list<int>::iterator itr=graph[source].begin(); itr!=graph[source].end(); itr++)
    {
        if(!visited[*itr]) dfs(graph, nodes, *itr, visited);
    }
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
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> store(nodes+1, INT_MAX);
    vector<bool> visited(nodes+1, false);
    vector<int> parent(nodes+1, -1);
    pq.push(make_pair(0, source));
    store[source] = 0;
    while(!pq.empty())
    {
        pair<int,int> idx = pq.top();
        pq.pop();
        if(visited[idx.second]==true) continue;
        visited[idx.second]=true;
        for(auto i=0; i<graph[idx.second].size(); i++)
        {
            if(!visited[graph[idx.second][i].first] && store[graph[idx.second][i].first]>graph[idx.second][i].second)
            {
                store[graph[idx.second][i].first] = graph[idx.second][i].second;
                pq.push(make_pair(graph[idx.second][i].second, graph[idx.second][i].first));
                parent[graph[idx.second][i].first] = idx.second;
            }
        }
    }
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
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(nodes+1, INT_MAX);
    pq.push(make_pair(0, source));
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
    // vector<int> weights = {256, 424, 3, 86, 183, 286, 89, 427, 118, 258, 333, 433, 170, 155, 222, 190, 477, 330, 369, 193, 426, 56, 435, 50, 442, 13, 146, 61, 219 };
    // vector<int> values = {647, 363, 887, 876, 434, 870, 143, 845, 417, 882, 999, 323, 652, 22, 700, 558, 477, 893, 390, 76, 713, 601, 511, 4, 870, 862, 689, 402, 790};
    // int threshold = 754;
    // cout<<knapsacktopdown(weights, values, threshold);
    ////////////////
    // string A = "abbcdgf";
    // string B = "bbadcgf";
    // cout<<longestsubseq(A, B);
    ////////////////
    // vector<int> A = {40, 20, 30, 10, 30};
    // cout<<mcm(A);
    //////////////////
    // string A = "aabbbabaaabbbabaabaab";
    // vector<string> B = {"bababbbb", "bbbabaa", "abbb", "a", "aabbaab", "b", "babaabbbb", "aa", "bb"};
    // unordered_set<string> count;
    // dp.clear();
    // for(int i=0; i<B.size(); i++)
    // {
    //     count.insert(B[i]);
    // }
    // int size = A.size();
    // vector<string> atop = recursor(count, A, 0, size);
    //////////////////////
    vector<pair<int,int>> det;
    det.push_back(make_pair(1,2));
    det.push_back(make_pair(1,5));
    det.push_back(make_pair(1,3));
    det.push_back(make_pair(2,5));
    det.push_back(make_pair(5,4));
    det.push_back(make_pair(5,6));
    det.push_back(make_pair(3,4));
    det.push_back(make_pair(4,6));
    int nodes = 6;
    vector<list<int>> mo = adirectedgraphcompiler(det, nodes);
    vector<bool> visited(nodes+1, false);
    for (int source = 1; source <= nodes; source++)
    {
        if(visited[source] == false) dfs(mo, nodes, source, visited);
    }

}
////////////////////////////////
/*
int bfs(vector<vector<pair<int,int>>> graph, int nodes, int start, int end, vector<vector<int>>& dp)
{
    vector<bool> visited(nodes+1, false);
    if(dp[start][end] != -1) return dp[start][end];
    if(dp[end][start] != -1) return dp[end][start];
    queue<pair<int,int>> q;
    q.push(make_pair(0, start));
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        if(dp[start][end] != -1) return dp[start][end];//=max(dp[p.second][end], p.first);
        if(p.second == end)
        {
            dp[start][end] = p.first;
            dp[end][start] = p.first;
            return p.first;
        }
        visited[p.second]=true;
        for(int i=0; i<graph[p.second].size(); i++)
        {
            if(!visited[graph[p.second][i].second])
            {
                q.push(make_pair(max(p.first, graph[p.second][i].first),graph[p.second][i].second));
                dp[start][graph[p.second][i].second] = max(p.first, graph[p.second][i].first);
            }
        }
    }
}
vector<int> Solution::solve(vector<vector<int> > &A, vector<vector<int> > &B) {
    int nodes=0;
    for(int i=0; i<A.size(); i++)
    {
        nodes=max({A[i][0], A[i][1], nodes});
    }
    vector<vector<pair<int,int>>> graph(nodes+1);
    for(int i=0; i<A.size(); i++)
    {
        graph[A[i][0]].push_back(make_pair(A[i][2],A[i][1]));
        graph[A[i][1]].push_back(make_pair(A[i][2],A[i][0]));
    }
    vector<int> ans;
    vector<vector<int>> dp;
    dp.clear();
    dp.resize(nodes+1, vector<int>(nodes+1, -1));
    for(int i=0; i<B.size(); i++)
    {
        int t = bfs(graph, nodes, B[i][0], B[i][1], dp);
        ans.push_back(t);
        // visited.clear();
    }
    return ans;
}
/////////jhhhhhhhhhhhhhhhhhhhhhhhhhhh
nt maxer(vector<vector<int>> A)
{
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> dp(n, vector<int> (m));
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(j=0)
            {
                dp[j][i]=A[j][i];
            }
            else 
            {
                dp[j][i] = dp[j-1][i]*A[j][i]+A[j][i];
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            
        }
    }
}
int Solution::solve(vector<vector<int> > &A) {
    return maxer(A);
}
*/
