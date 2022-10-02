/* Problem Link - https://www.interviewbit.com/problems/path-with-good-nodes/

Problem Description

Given a tree with N nodes labelled from 1 to N.

Each node is either good or bad denoted by binary array A of size N where if A[i] is 1 then ithnode is good else if A[i] is 
0 then ith node is bad.

Also the given tree is rooted at node 1 and you need to tell the number of root to leaf paths in the tree that contain not more than C good nodes.

NOTE:

Each edge in the tree is bi-directional.


Problem Constraints
2 <= N <= 105

A[i] = 0 or A[i] = 1

0 <= C <= N



Input Format
First argument is an binary integer array A of size N.

Second argument is a 2-D array B of size (N-1) x 2 denoting the edge of the tree.

Third argument is an integer C.



Output Format
Return an integer denoting the number of root to leaf paths in the tree that contain not more than C good nodes.



Example Input
Input 1:

 A = [0, 1, 0, 1, 1, 1]
 B = [  [1, 2]
        [1, 5]
        [1, 6]
        [2, 3]
        [2, 4]
     ]
 C = 1


Example Output
Output 1:

 3


Example Explanation
Explanation 1:

 Path (1 - 2 - 3) and (1 - 5) and (1 - 6) are the paths which contain atmost C nodes.
*/
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> &A, vector<bool> &visited, int C,int u,vector<vector<int> > &adj, int &count,int good)
{
    if(good+A[u-1]>C)
    return ;
    if(adj[u].size()==1 && !visited[u] && C>=good+A[u-1])
    {count++;return;}
    visited[u]=true;
    for(int i=0;i<adj[u].size();i++)
    {
        if(!visited[adj[u][i]])
        {
          dfs(A,visited,C,adj[u][i],adj,count,good+A[u-1]);     
        }
    }
 return ;   
}
int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int count = 0;
    vector<bool> visited(A.size()+1,false);
    vector<vector<int> > adj(A.size()+1);
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
  dfs(A,visited,C,1,adj,count,0);
  return count;
}