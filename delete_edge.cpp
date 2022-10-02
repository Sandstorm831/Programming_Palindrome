/*Problem Link - https://www.interviewbit.com/problems/delete-edge/

Problem Description

Given a undirected tree with N nodes labeled  from 1 to N.

Each node has a certain weight assigned to it given by an integer array A of size N.

You need to delete an edge in such a way that Product between sum of weight of nodes in one subtree with sum of weight of nodes in other subtree is maximized.

Return this maximum possible product modulo 109 + 7.

NOTE:

The tree is rooted at node labeled with 1.


Problem Constraints
2 <= N <= 105

1 <= A[i] <= 103



Input Format
First argument is an integer array A of size N denoting the weight of each node.

Second argument is a 2-D array B of size (N-1) x 2 denoting the edge of the tree.



Output Format
Return a single integer denoting the maximum product prossible of sum of weights of nodes in the two subtrees formed by deleting an edge with modulo 109 + 7.



Example Input
Input 1:

 A = [10, 5, 12, 6]
 B = [

        [1, 2]
        [1, 4]
        [4, 3]
     ]
Input 2:

 A = [11, 12]
 B = [

        [1, 2]
     ]


Example Output
Output 1:

 270
Output 2:

 132


Example Explanation
Explanation 1:

 Removing edge (1, 4) created two subtrees.
 Subtree-1 contains nodes (1, 2) and Subtree-2 contains nodes (3, 4)
 So product will be = (A[1] + A[2]) * (A[3] + A[4]) = 15 * 18 = 270
Explanation 2:

 Removing edge (1, 2) created two subtrees.
 Subtree-1 contains node (1) and Subtree-2 contains node (3)
 So product will be = (A[1]) * (A[2]) = 11 * 12 = 132
*/
#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;
void dfs(int node, int parent, long long total, vector<vector<int>>& graph, vector<int>& subtree, long long& ans)
{   
    int sum=subtree[node-1]%mod;
    for(int i=0;i<graph[node].size(); i++)
    {
        if(graph[node][i]!=parent)
        {
            dfs(graph[node][i], node, total, graph, subtree, ans);
            sum+=subtree[graph[node][i]-1];
        }
    }
    subtree[node-1]=sum;
    long long apb = (total-sum)*(sum);
    ans = max((long long)ans, apb);
}
int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    int n = A.size();
    vector<vector<int>> graph(n+1);
    for(int i=0; i<B.size(); i++)
    {
        graph[B[i][0]].push_back(B[i][1]);
        graph[B[i][1]].push_back(B[i][0]);
    }
    long long sum=0;
    vector<int> subtree(n);
    for(int i=0; i<A.size(); i++)
    {
        subtree[i] = A[i]; 
        sum+=A[i];
    }
    long long int ans = INT_MIN;
    dfs(1,0,sum, graph, subtree, ans);
    return ans%mod;
    
}