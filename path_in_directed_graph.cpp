/* Problem Link - https://www.interviewbit.com/problems/path-in-directed-graph/
Problem Description

Given an directed graph having A nodes labelled from 1 to A containing M edges given by matrix B of size M x 2such that there is a edge directed from node

B[i][0] to node B[i][1].

Find whether a path exists from node 1 to node A.

Return 1 if path exists else return 0.

NOTE:

There are no self-loops in the graph.
There are no multiple edges between two nodes.
The graph may or may not be connected.
Nodes are numbered from 1 to A.
Your solution will run on multiple test cases. If you are using global variables make sure to clear them.


Problem Constraints
2 <= A <= 105

1 <= M <= min(200000,A(A-1))

1 <= B[i][0], B[i][1] <= A



Input Format
The first argument given is an integer A representing the number of nodes in the graph.

The second argument given a matrix B of size M x 2 which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].



Output Format
Return 1 if path exists between node 1 to node A else return 0.



Example Input
Input 1:

 A = 5
 B = [  [1, 2] 
        [4, 1] 
        [2, 4] 
        [3, 4] 
        [5, 2] 
        [1, 3] ]


Output 1:

 0
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
void dfs(int source)
{
    visited[source] = true;
    for(auto itr:graph[source])
    {
        if(!visited[itr]) dfs(itr);   
    }
}
int Solution::solve(int A, vector<vector<int> > &B) {
    graph.clear();
    graph.resize(A+1);
    visited.clear();
    visited.resize(A+1, false);
    for(int i=0; i<B.size(); i++)
    {
        graph[B[i][0]].push_back(B[i][1]);
    }
    dfs(1);
    return visited[A];
}