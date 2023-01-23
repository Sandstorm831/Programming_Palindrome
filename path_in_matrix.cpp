// Problem Link - https://www.interviewbit.com/problems/path-in-matrix/
#include <bits/stdc++.h>
using namespace std;
void dfs(int i, int j, int row, int column, int dsx, int dsy, vector<vector<int>>& A)
{
    if(i<0||j<0||i>=row||j>=column||A[i][j]==0) return;
    if(i==dsx && j==dsy)
    {
        A[i][j]=0;
        return;
    }
    A[i][j]=0;
    dfs(i+1,j,row,column, dsx, dsy, A);
    dfs(i-1,j,row,column, dsx, dsy, A);
    dfs(i,j+1,row,column, dsx, dsy, A); 
    dfs(i,j-1,row,column, dsx, dsy, A);
    return;
}
int checkPath(vector<vector<int> > &A) {
    int scx,scy,dex,dey;
    int row = A.size();
    int col = A[0].size();
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(A[i][j] == 1) scx = i,scy = j;
            else if(A[i][j] == 2) dex = i, dey = j;
        }
    }
    dfs(scx,scy,row,col,dex,dey,A);
    if(A[dex][dey] == 0) return 1;
    return 0;
}