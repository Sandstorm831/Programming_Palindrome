// Problem Link - https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/
/*
int maxer(vector<vector<int>> A)
{
    int n = A.size(); 
    int m = A[0].size();
    vector<vector<int>> dp(n, vector<int> (m,0));
    for(int i=0; i<m; i++)
    {
        int pred=0;
        for(int j=0; j<n; j++)
        {
            if(A[j][i] == 1)
            {
                dp[j][i] = ++pred;
            }
            else pred=0;
        }
    }
    for(int i=0; i<n; i++)
    {
        sort(dp[i].begin(), dp[i].end());
        reverse(dp[i].begin(), dp[i].end());
    }
    int maxy = INT_MIN;
    for(int i=0; i<n; i++)
    {
        int maxx = INT_MIN;
        for(int j=0; j<m; j++)
        {
            maxx = max(maxx, (j+1)*dp[i][j]);
        }
        maxy = max(maxy, maxx);
    }
    return maxy;
}
int Solution::solve(vector<vector<int> > &A) {
    int maxr = maxer(A);
    return maxr;
}
*/
#include <bits/stdc++.h>
using namespace std;
int maxer(vector<vector<int>> A)
{
    int n = A.size(); 
    int m = A[0].size();
    vector<vector<int>> dp(n, vector<int> (m,0));
    for(int i=0; i<m; i++)
    {
        int pred=0;
        for(int j=0; j<n; j++)
        {
            if(A[j][i] == 1)
            {
                dp[j][i] = ++pred;
            }
            else pred=0;
        }
    }
    for(int i=0; i<n; i++)
    {
        sort(dp[i].begin(), dp[i].end());
        reverse(dp[i].begin(), dp[i].end());
    }
    int maxy = INT_MIN;
    for(int i=0; i<n; i++)
    {
        int maxx = INT_MIN;
        for(int j=0; j<m; j++)
        {
            maxx = max(maxx, (j+1)*dp[i][j]);
        }
        maxy = max(maxy, maxx);
    }
    return maxy;
}
int main()
{
    vector<vector<int>> A = A = {{1, 0, 1},{0, 1 ,0},{1, 0, 0}};
    int maxr = maxer(A);
    return maxr;
}