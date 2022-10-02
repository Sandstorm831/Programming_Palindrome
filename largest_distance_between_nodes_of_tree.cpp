/* Problem Link -https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/

Problem Description

Given an arbitrary unweighted rooted tree which consists of N nodes.

The goal of the problem is to find largest distance between two nodes in a tree.

Distance between two nodes is a number of edges on a path between the nodes (there will be a unique path between any pair of nodes since it is a tree).

The nodes will be numbered 0 through N - 1.

The tree is given as an array A, there is an edge between nodes A[i] and i (0 <= i < N). Exactly one of the i's will have A[i] equal to -1, it will be root node.



Problem Constraints
1 <= N <= 40000



Input Format
First and only argument is an integer array A of size N.



Output Format
Return a single integer denoting the largest distance between two nodes in a tree.



Example Input
Input 1:

 A = [-1, 0, 0, 0, 3]


Example Output
Output 1:

 3


Example Explanation
Explanation 1:

 node 0 is the root and the whole tree looks like this: 
          0
       /  |  \
      1   2   3
               \
                4

 One of the longest path is 1 -> 0 -> 3 -> 4 and its length is 3, thus the answer is 3.
*/
#include <bits/stdc++.h>
using namespace std;
pair<int,int> recursor(vector<vector<int>>& graph, int node, vector<bool>& visited)
{
    if(graph[node].size()==0) return make_pair(0,0);
    pair<int,int> store;
    store.first = 0; store.second=0;
    visited[node]=true;
    for(int i=0; i<graph[node].size(); i++)
    {
        if(visited[graph[node][i]]) continue;
        pair<int,int> temp;
        temp = recursor(graph, graph[node][i], visited);
        store.second = max(store.second, temp.first+store.first);
        if(temp.first > store.first)
        {
            store.first = temp.first;
        }
        store.second = max(temp.second, store.second);
    }
    store.first +=1;
    return store;
}
int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> graph(n);
    int node;
    for(int i=0; i<n; i++)
    {
        if(A[i]!=-1)
        {
            graph[i].push_back(A[i]);
            graph[A[i]].push_back(i);
        }
        else 
        {
            node = i;
            continue;
        }
    }
    pair<int,int> idx;
    vector<bool> visited(n,false);
    idx = recursor(graph, node, visited);
    return max(idx.first-1, idx.second);
}