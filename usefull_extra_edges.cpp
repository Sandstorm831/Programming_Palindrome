/*
Problem Link - https://www.interviewbit.com/problems/useful-extra-edges/
Given a graph of A nodes. Also given the weighted edges in the form of array B.

You are also given starting point C and destination point D.

Also given are some extra edges in the form of vector E.

You need to find the length of the shortest path from C to D if you can use maximum one road from the given roads in E.

All roads are bidirectional.



Problem Constraints
1 <= A <= 100000

1 <= |B| <= 100000

1 <= C, D <= A

1 <= |E| <= 300

All lengths of the roads lie between 1 and 1000.



Input Format
First argument is the integer A.

Second argument is the vector of vectors B.

Third argument is the integer C.

Fourth argument is the integer D.

Fifth argument is the vector of vectors E.



Output Format
Return -1 if C is not reachable from D. Else return the shortest distance between them.



Example Input
Input 1:

 A = 3
B = [   [1, 2, 1]
        [2, 3, 2]
    ]
C = 1
D = 3
E = [   [1, 3, 2]
    ]
Input 2:

 A = 4
B = [   [1, 2, 1]
        [2, 3, 2]
        [3, 1, 4]
    ]
C = 1
D = 4
E = [   [1, 3, 2]
    ]


Example Output
Output 1:

 2
Output 2:

 -1


Example Explanation
Explanation 1:

 Use the direct edge from 1 to 3. It has shortest path from 1 to 3.
Explanation 2:

 4 cannot be reached from 1.
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(vector<vector<pair<int,int>>>& graph, int nodes, int source)
{
    vector<int> distances(nodes+1, INT_MAX/2-2200);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, source));
    distances[source]=0;
    while(!pq.empty())
    {
        pair<int,int> idx = pq.top();
        pq.pop();
        for(int i=0; i<graph[idx.second].size(); i++)
        {
            if(distances[graph[idx.second][i].second] > distances[idx.second]+graph[idx.second][i].first)
            {
                distances[graph[idx.second][i].second] = distances[idx.second]+graph[idx.second][i].first;
                pq.push(make_pair(graph[idx.second][i].first, graph[idx.second][i].second));
            }
        }
    }
    return distances;
}
int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {
    vector<vector<pair<int,int>>> graph(A+1);
    for(int i=0; i<B.size(); i++)
    {
        graph[B[i][0]].push_back(make_pair(B[i][2], B[i][1]));
        graph[B[i][1]].push_back(make_pair(B[i][2], B[i][0]));
    }
    vector<int> c_d = dijkstra(graph, A, C);
    vector<int> d_c = dijkstra(graph, A, D);
    int mindist = c_d[D];
    for(int i=0; i<E.size(); i++)
    {
        int node_a = E[i][0];
        int node_b = E[i][1];
        mindist = min(min(mindist , c_d[node_a]+E[i][2]+d_c[node_b]) , c_d[node_b]+E[i][2]+d_c[node_a]);
    }
    if(mindist > INT_MAX/2-10000) return -1;
    return mindist;
    
}