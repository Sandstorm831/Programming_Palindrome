// Problem Link - https://www.interviewbit.com/problems/maximum-path-in-triangle/
/*
int matrixer(vector<vector<int>> A)
{
    int n = A.size();
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j==0)
            {
                A[i][j] += A[i-1][j];
            }
            else if(j==i)
            {
                A[i][j] += A[i-1][j-1];
            }
            else
            {
                A[i][j] += max(A[i-1][j], A[i-1][j-1]);
            }
        }
    }
    int maxx=INT_MIN;
    for(int i=0; i<n; i++)
    {
        maxx = max(maxx, A[n-1][i]);
    }
    return maxx;
}
int Solution::solve(vector<vector<int> > &A) {
    return matrixer(A);
}
*/
#include <bits/stdc++.h>
using namespace std;
int matrixer(vector<vector<int>> A)
{
    int n = A.size();
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j==0)
            {
                A[i][j] += A[i-1][j];
            }
            else if(j==i)
            {
                A[i][j] += A[i-1][j-1];
            }
            else
            {
                A[i][j] += max(A[i-1][j], A[i-1][j-1]);
            }
        }
    }
    int maxx=INT_MIN;
    for(int i=0; i<n; i++)
    {
        maxx = max(maxx, A[n-1][i]);
    }
    return maxx;
}
int main()
{
    vector<vector<int>>  A = {{3, 0, 0, 0},{7, 4, 0, 0},{2, 4, 6, 0},{8, 5, 9, 3}};
    cout<<matrixer(A);
}