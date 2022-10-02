/* Problem LInk - https://www.interviewbit.com/problems/capture-regions-on-board/
Problem Description

Given a 2D character matrix A of size N x M, containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.



Problem Constraints
1 <= N, M <= 103



Input Format
First and only argument 2D character matrix A of size N X M.



Output Format
Make changes to the the input only as matrix is passed by reference.



Example Input
Input 1:

 A = [  [X, X, X, X],
        [X, O, O, X],
        [X, X, O, X],
        [X, O, X, X]
     ]


Example Output
Output 1:

 A = [  [X, X, X, X],
        [X, X, X, X],
        [X, X, X, X],
        [X, O, X, X]
     ]


Example Explanation
Explanation 1:

 'O' in (4,2) is not surrounded by X from below.
*/
#include <bits/stdc++.h>
using namesapce std;
vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,-1,0,1};
bool checker(int i, int j, int a, int b)
{
    if(i<0 || j<0 || i>a || j>b) return false;
    return true;
}
void recursor(int i, int j, int a, int b, vector<vector<char>>& A)
{
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    while(!q.empty())
    {
        pair<int,int> idx = q.front();
        q.pop();
        A[idx.first][idx.second]='Y';
        for(int i=0; i<4; i++)
        {
            int xx = idx.first+dx[i];
            int yy = idx.second+dy[i];
            if(!checker(xx,yy,a,b) || A[xx][yy] == 'Y' || A[xx][yy] == 'X') continue;
            else if(A[xx][yy] == 'O')
            {
                q.push(make_pair(xx,yy));
            }
        }
    }
}
void helper(vector<vector<char>> &A)
{
    int n = A.size();
    int m = A[0].size();
    for(int i=0; i<n; i++)
    {
        if(A[i][0] == 'O') recursor(i,0, n-1, m-1, A);
        if(A[i][m-1] == 'O') recursor(i,m-1, n-1, m-1, A);
    }
    for(int i=1; i<m-1; i++)
    {
        if(A[0][i] == 'O') recursor(0,i, n-1, m-1, A);
        if(A[n-1][i] == 'O') recursor(n-1,i, n-1, m-1, A);
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(A[i][j] != 'Y') A[i][j]='X';
            else A[i][j] = 'O';
        }
    }
}
void Solution::solve(vector<vector<char> > &A) {
    helper(A);
}