/*Problem Link - https://www.interviewbit.com/problems/good-graph/

Given a directed graph of N nodes where each node is pointing to any one of the N nodes (can possibly point to itself). Ishu, the coder, is bored and he has discovered a problem out of it to keep himself busy. Problem is as follows:

A node is 'good'if it satisfies one of the following:

1. It is the special node (marked as node 1)
2. It is pointing to the special node (node 1)
3. It is pointing to a good node.
Ishu is going to change pointers of some nodes to make them all ‘good’. You have to find the min. number of pointers to change in order to

make all the nodes good (Thus, a Good Graph).

Note: Resultant Graph should hold the property that all nodes are good and each node must point to exactly one node.

Constraints:

1 <= N <= 100,000
Input:

A vector of N integers containing N numbers all between 1 to N, where i-th number is the number of node that i-th node is pointing to.
Output:

An Integer denoting min. number of pointer changes.
Example:

input: [1, 2, 1, 2]
output: 1 (Pointer of node 2 is made to point to node 1)

input: [3, 1, 3, 1]
output: 1 (Pointer of node 3 is made to point to node 1)
*/
#include <bits/stdc++.h>
using namesapce std;
void dfs(vector<int> &A, vector<bool>& visited, int node, int& ans)
{
    if(visited[node]) return;
    visited[node] = true;
    if(A[node-1] == 1) return;
    if(!visited[A[node-1]]) return dfs(A, visited, A[node-1], ans);
    ans++;
    A[node-1]=1;
    return;
}
int Solution::solve(vector<int> &A) {
    int n = A.size();
    int ans=0;
    for(int i=1; i<A.size(); i++)
    {
        vector<bool> visited(n+1,false);
        if(!visited[i+1]) dfs(A, visited, i+1, ans);
    }
    return ans;
}