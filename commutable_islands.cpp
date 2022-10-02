/*Problem Link - https://www.interviewbit.com/problems/commutable-islands/

There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.

We need to find bridges with minimal cost such that all islands are connected.

It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.

Input Format:

The first argument contains an integer, A, representing the number of islands.
The second argument contains an 2-d integer matrix, B, of size M x 3:
    => Island B[i][0] and B[i][1] are connected using a bridge of cost B[i][2].
Output Format:

Return an integer representing the minimal cost required.
Constraints:

1 <= A, M <= 6e4
1 <= B[i][0], B[i][1] <= A
1 <= B[i][2] <= 1e3
Examples:

Input 1:
    A = 4
    B = [   [1, 2, 1]
            [2, 3, 4]
            [1, 4, 3]
            [4, 3, 2]
            [1, 3, 10]  ]

Output 1:
    6

Explanation 1:
    We can choose bridges (1, 2, 1), (1, 4, 3) and (4, 3, 2), where the total cost incurred will be (1 + 3 + 2) = 6.

Input 2:
    A = 4
    B = [   [1, 2, 1]
            [2, 3, 2]
            [3, 4, 4]
            [1, 4, 3]   ]

Output 2:
    6

Explanation 2:
    We can choose bridges (1, 2, 1), (2, 3, 2) and (1, 4, 3), where the total cost incurred will be (1 + 2 + 3) = 6.

*/
#include <bits/stdc++.h>
using namespace std;
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<pair<int,int>>> graph(A+1);
    for(int i=0; i<B.size(); i++)
    {
        graph[B[i][0]].push_back(make_pair(B[i][2], B[i][1]));
        graph[B[i][1]].push_back(make_pair(B[i][2], B[i][0]));
    }
    vector<int> keys(A+1, INT_MAX);
    vector<int> parent(A+1, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> visited(A+1, false);
    pq.push(make_pair(0,1));
    keys[1]=0;
    while(!pq.empty())
    {
        pair<int,int> xd = pq.top();
        pq.pop();
        visited[xd.second]=true;
        for(int i=0; i<graph[xd.second].size(); i++)
        {
            if(!visited[graph[xd.second][i].second] && keys[graph[xd.second][i].second] >  graph[xd.second][i].first)
            {
                keys[graph[xd.second][i].second] = graph[xd.second][i].first;
                pq.push(make_pair(graph[xd.second][i].first, graph[xd.second][i].second));
                parent[graph[xd.second][i].second] = xd.second;
            }
        }
    }
    int sum=0; 
    for(int i=1; i<keys.size(); i++)
    {
        sum += keys[i];
    }
    return sum;
}