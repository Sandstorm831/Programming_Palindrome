/* Problem Link - https://www.interviewbit.com/problems/black-shapes/

Given N x M character matrix A of O's and X's, where O = white, X = black.


Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)




Input Format:

    The First and only argument is a N x M character matrix.
Output Format:

    Return a single integer denoting number of black shapes.
Constraints:

    1 <= N,M <= 1000
    A[i][j] = 'X' or 'O'
Example:

Input 1:
    A = [ OOOXOOO
          OOXXOXO
          OXOOOXO  ]
Output 1:
    3
Explanation:
    3 shapes are  :
    (i)    X
         X X
    (ii)
          X
    (iii)
          X
          X
Note: we are looking for connected shapes here.

XXX
XXX
XXX
is just one single connected black shape.
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, -1, 0, 1};
bool ifexist(int x, int y, int ux, int uy)
{
    if(x<0 || y<0 || x >= ux || y >= uy) return false;
    return true;
}
void bfs(vector<string>& A, vector<vector<bool>>& visited, int x, int y)
{
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        pair<int,int> idx = q.front();
        q.pop();
        visited[idx.first][idx.second]=true;
        for(int i=0; i<4; i++)
        {
            int xx = idx.first + dx[i]; 
            int yy = idx.second + dy[i];
            if(ifexist(xx, yy, A.size() , A[0].size()) && A[xx][yy] == 'X') 
            {
                if(!visited[xx][yy]) q.push(make_pair(xx,yy));
            }
        }
    }
}
int Solution::black(vector<string> &A) {
    int n = A.size();
    int m = A[0].size();
    int counter=0;
    vector<vector<bool>> visited(n, vector<bool> (m, false));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(!visited[i][j] && A[i][j]=='X')
            {
                counter++;
                bfs(A, visited, i, j);
            }
        }
    }
    return counter;
}