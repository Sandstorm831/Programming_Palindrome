#include <bits/stdc++.h>
using namespace std;
/* Problem Link - https://www.interviewbit.com/problems/valid-path/
bool check(int x, int y, int R, vector<int> E, vector<int> F)
{
    int rr = R*R;
    for(int i=0; i<E.size();i++)
    {
        int xx = (x-E[i])*(x-E[i]);
        int yy = (y-F[i])*(y-F[i]);
        if(xx+yy<=rr) return true;
    }
    return false;
}
bool safe(int a, int b, int x, int y)
{
    if(x<=a&&x>=0&&y<=b&&y>=0) return true;
    return false;
}
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<bool>> visited(A+1, vector<bool> (B+1, false));
    queue<pair<int,int>> q;
    visited[0][0]=true;
    q.push(make_pair(0,0));
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==A&&y==B) return "YES";
        for(int i=-1;i<2;i++)
        {
            for(int j=-1;j<2;j++)
            {
                if(!check(x+i, y+j, D, E,F)&&safe(A,B,x+i,y+j)&&!visited[x+i][y+j])
                {
                    q.push(make_pair(x+i,y+j));
                    visited[x+i][y+j]=true;
                }
            }
        }
    }
    return "NO";
}
*/
bool check(int x, int y, int R, vector<int> E, vector<int> F)
{
    int rr = R*R;
    for(int i=0; i<E.size();i++)
    {
        int xx = (x-E[i])*(x-E[i]);
        int yy = (y-F[i])*(y-F[i]);
        if(xx+yy<=rr) return true;
    }
    return false;
}
bool safe(int a, int b, int x, int y)
{
    if(x<=a&&x>=0&&y<=b&&y>=0) return true;
    return false;
}
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<bool>> visited(A+1, vector<bool> (B+1, false));
    queue<pair<int,int>> q;
    visited[0][0]=true;
    q.push(make_pair(0,0));
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==A&&y==B) return "YES";
        for(int i=-1;i<2;i++)
        {
            for(int j=-1;j<2;j++)
            {
                if(!check(x+i, y+j, D, E,F)&&safe(A,B,x+i,y+j)&&!visited[x+i][y+j])
                {
                    q.push(make_pair(x+i,y+j));
                    visited[x+i][y+j]=true;
                }
            }
        }
    }
    return "NO";
}