/* Problem Link - https://www.interviewbit.com/problems/min-cost-path/

Problem Description

You are given a AB character matrix named C. Every cell in C has a character U,R,L or D indicating up,right,left and down.

Your target is to go from top left corner to the bottom right corner of the matrix.

But there are some restrictions while moving along the matrix:

If you follow what is written in the cell then you can move freely.
But if you don't follow what is written in the cell then you have to pay 1 unit of cost.
Like: If a cell contains character U and you go right instead of Up you have to pay 1 unit of cost.

So your task is to find the minimum cost to go from top-left corner to the bottom-right corner.



Problem Constraints
1 <= A,B <= 103
C[i][j] can be either U,R,L or D.


Input Format
First Argument represents a integer A (number of rows).
Second Argument represents a integer B (number of columns).
Third Argument represents a string array C which contains A strings each of length B.


Output Format
 Return an integer denoting the minimum cost to travel from top-left corner to bottom-right corner.



Example Input
Input:1

 A = 3
 B = 3
 C = ["RRR","DDD","UUU"]
Input:2

 A = 1
 B = 4
 C = ["LLLL"]


Example Output
Output-1 :

 1
Output-2 :

 3


Example Explanation*
Explanation for Input-1:

 Matrix looks like: RRR
                    DDD
                    UUU
 We go right two times and down two times.
 So from top-right cell we are going down though right is given so this incurs a cost of 1.
Explanation for Input-2:

 Matrix looks like: LLLL
 We go right three times.
*/


#include <bits/stdc++.h>
using namespace std;


/* MLE error code
bool checker(int a, int b, int ua, int  ub)
{
    if(a<0 || a>=ua || b<0 || b>=ub) return false;
    return true;
}
int dijkstramod(vector<vector<pair<int,int>>>& graph)
{
    int k = graph.size();
    vector<bool> visited(k+1, false);
    vector<int> dist(k, INT_MAX);
    deque<pair<int,int>> q;
    q.push_front(make_pair(1,0));
    dist[1]=0;
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop_front();
        visited[p.first]=true;
        for(int i=0; i<graph[p.first].size(); i++)
        {
            if(dist[graph[p.first][i].first] > dist[p.first]+graph[p.first][i].second) 
            {
                dist[graph[p.first][i].first] = dist[p.first]+graph[p.first][i].second;
            }
            if(!visited[graph[p.first][i].first] && graph[p.first][i].second == 0) q.push_front(make_pair(graph[p.first][i].first, dist[graph[p.first][i].first]));
            else if(!visited[graph[p.first][i].first]) q.push_back(make_pair(graph[p.first][i].first, dist[graph[p.first][i].first]));
        }
    }
    return dist[k-1];
}
int Solution::solve(int A, int B, vector<string> &C) {
    vector<vector<pair<int,int>>> graph(A*B+1);
    int k=0;
    for(int i=0; i<A; i++)
    {
        for(int j=0; j<B; j++)
        {
            k++;
            char s = C[i][j];
            if(s == 'R')
            {
                if(checker(i, j+1, A, B)) graph[k].push_back(make_pair(k+1,0));
                if(checker(i, j-1, A, B)) graph[k].push_back(make_pair(k-1,1));
                if(checker(i-1, j, A, B)) graph[k].push_back(make_pair(k-B, 1));
                if(checker(i+1, j, A, B)) graph[k].push_back(make_pair(k+B, 1));
            }
            else if(s == 'L')
            {
                if(checker(i, j+1, A, B)) graph[k].push_back(make_pair(k+1,1));
                if(checker(i, j-1, A, B)) graph[k].push_back(make_pair(k-1,0));
                if(checker(i-1, j, A, B)) graph[k].push_back(make_pair(k-B, 1));
                if(checker(i+1, j, A, B)) graph[k].push_back(make_pair(k+B, 1));
            }
            else if(s == 'U')
            {
                if(checker(i, j+1, A, B)) graph[k].push_back(make_pair(k+1,1));
                if(checker(i, j-1, A, B)) graph[k].push_back(make_pair(k-1,1));
                if(checker(i-1, j, A, B)) graph[k].push_back(make_pair(k-B, 0));
                if(checker(i+1, j, A, B)) graph[k].push_back(make_pair(k+B, 1));
            }
            else if(s == 'D')
            {
                if(checker(i, j+1, A, B)) graph[k].push_back(make_pair(k+1,1));
                if(checker(i, j-1, A, B)) graph[k].push_back(make_pair(k-1,1));
                if(checker(i-1, j, A, B)) graph[k].push_back(make_pair(k-B, 1));
                if(checker(i+1, j, A, B)) graph[k].push_back(make_pair(k+B, 0));
            }
        }
    }
    return dijkstramod(graph);
}
*/
/////////////////////
const int INF = 1e9 + 10;


bool checkValid(int x , int y , int n , int m) {

 return (x >= 0 && x < n && y >= 0 && y < m); 

}
int Solution::solve(int A, int B, vector<string> &C) {
    vector<vector<int>> d(A , vector<int>(B , INF));
    deque<pair<int , int>> q;
    q.push_front({0 , 0});
    d[0][0] = 0;
    unordered_map<char , pair<int , int>> mp;
    mp['U'] = {-1 , 0};
    mp['L'] = {0 ,-1};
    mp['D'] = {1 , 0};
    mp['R'] = {0 , 1};
    string s = "URDL";
    while(!q.empty()) 
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        int wt;
        int dx , dy;
        for (char &c : s) {  
            dx = mp[c].first;
            dy = mp[c].second;  
            wt = 1 - (c == C[x][y]); 
            if(checkValid(x + dx , y + dy , A , B))
            {
                if(d[x][y] + wt < d[x + dx][y + dy]) 
                {
                    d[x + dx][y + dy] = d[x][y] + wt;
                    if(wt) q.push_back({x + dx , y + dy}); 
                    else q.push_front({x + dx , y + dy}); 
                }
            }
        } 
    }
    return d[A - 1][B - 1];
}
