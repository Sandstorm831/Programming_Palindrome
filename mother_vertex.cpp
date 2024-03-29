/* Problem Link - https://www.interviewbit.com/problems/mother-vertex/

Problem Description
 
 

You are given a directed graph with A vertices and M edges.

You are given an array B with dimensions M x 2, where each row denotes a directed edge from Bi, 0 to Bi, 1.

You need to find if there exists a mother vertex in the given graph. Return 1 if it exists, otherwise 0.

A mother vertex is defined as a vertex from which all the vertices in the graph are accessible by a directed path.



Problem Constraints
1 <= A <= 105
1 <= M <= 2 * 105
1 <= Bi, 0, Bi, 1 <= A
There can be duplicate edges or self loops in the input graph.


Input Format
The first argument is the integer A. The second argument is the 2D integer array B.


Output Format
Return a single integer 1 if a mother vertex exists, otherwise 0.


Example Input
Input 1:
A = 3
B = [[1, 3], [2, 3], [1, 3]]
Input 2:

A = 3
B = [[1, 3], [2, 3], [3, 2]]


Example Output
Output 1:
0
Output 2:

1


Example Explanation
Explanation 1:
There is no vertex from which all the other vertices are accessible.
Note there can be duplicate edges.
Explanation 2:

Vertex 1 is the mother vertex. We can reach 2 using 1 -> 3 -> 2. We can reach 3 using 1 -> 3
*/
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& graph, vector<bool>& visited, int source)
{
    visited[source]=true;
    for(int i=0; i<graph[source].size(); i++)
    {
        if(!visited[graph[source][i]]) dfs(graph, visited, graph[source][i]);
    }
}
int Solution::motherVertex(int A, vector<vector<int> > &B) {
    vector<vector<int>> graph(A+1);
    vector<bool> visited(A+1, false);
    for(int i=0; i<B.size(); i++)
    {
        graph[B[i][0]].push_back(B[i][1]);
    }
    int mother;
    for(int i=1; i<=A; i++)
    {
        if(!visited[i]) 
        {
            mother=i;
            dfs(graph, visited, i);
        }
    }
    for(int i=1; i<=A; i++) visited[i]=false;
    dfs(graph, visited, mother);
    for(int i=1; i<=A; i++)
    {
        if(!visited[i]) return 0;
    }
    return 1;
}