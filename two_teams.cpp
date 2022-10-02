#include <bits/stdc++.h>
using namespace std;
/*
Problem Description

There are A people numbered 1 to A in a football academy.

The coach of the academy wants to make two teams (not necessary of equal size) but unfortunately, not all people get along, and several refuse to be put on the same team as that of their enemies.

Given a 2-D array B of size M x 2 denoting the enemies i.e B[i][0] and B[i][1] both are enemies of each other.

Return 1 if it possible to make exactly two teams else return 0.



Problem Constraints
2 <= A <= 105

1 <= M <= 105

1 <= B[i][0], B[i][1] <= A

B[i][0] != B[i][1]



Input Format
First argument is an integer A denoting number of peoples.

Second argument is a 2-D array B of size M x 2 denoting enemies.



Output Format
Return 1 if it possible to make exactly two teams else return 0.



Example Input
Input 1:

 A = 5
 B = [ [1, 2],
       [2, 3],
       [1, 5],
       [2, 4] ] 
Input 2:

 A = 4
 B = [ [1, 4],
       [3, 1],
       [4, 3],
       [2, 1] ]


Example Output
Output 1:

 1 
Output 2:

 0 


Example Explanation
Explanation 1:

 We can make two teams [1, 3, 4] and [2, 5].
Explanation 2:

 No possible way to create two teams. So, we need to return 0.
*/
bool recursor(vector<vector<int>>& graph, vector<int>& color, int node)
{
    color[node]=1;
    queue<int> q;
    q.push(node);
    while(!q.empty())
    {
        int idx = q.front();
        q.pop();
        for(int i=0; i<graph[idx].size(); i++)
        {
            if(color[graph[idx][i]] == -1)
            {
                color[graph[idx][i]] = 1-color[idx];
                q.push(graph[idx][i]);
            }
            else if(color[graph[idx][i]] == color[idx]) return false;
        }
    }
    return true;
}
bool bipartite_detected(vector<vector<int>>& graph, vector<int>& color, int A)
{
    
    for(int i=0; i<A; i++)
    {
        if(color[i] == -1)
        {
            if(recursor(graph, color, i ) == false) return false;
        }
    }
    return true;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> graph(A+1);
    for(int i=0; i<B.size(); i++)
    {
        graph[B[i][0]].push_back(B[i][1]);
        graph[B[i][1]].push_back(B[i][0]);
    }
    vector<int> color(A+1,-1);
    return bipartite_detected(graph, color, A);
}