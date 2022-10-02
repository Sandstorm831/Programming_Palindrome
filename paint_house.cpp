// Problem Link - https://www.interviewbit.com/problems/paint-house/
/* Problem Solution
int bottomup(vector<vector<int>> A)
{
    int n = A.size();
    vector<vector<int>> dp(n, vector<int> (3));
    dp[0][0] = A[0][0];
    dp[0][1] = A[0][1];
    dp[0][2] = A[0][2];
    for(int i=1; i<n;  i++)
    {
        dp[i][0] = A[i][0]+min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = A[i][1]+min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = A[i][2]+min(dp[i-1][1], dp[i-1][0]);
    }
    return min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
}
int Solution::solve(vector<vector<int> > &A) {
    return bottomup(A);
}
*/
#include <bits/stdc++.h>
using namesapces std;
int bottomup(vector<vector<int>> A)
{
    int n = A.size();
    vector<vector<int>> dp(n, vector<int> (3));
    dp[0][0] = A[0][0];
    dp[0][1] = A[0][1];
    dp[0][2] = A[0][2];
    for(int i=1; i<n;  i++)
    {
        dp[i][0] = A[i][0]+min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = A[i][1]+min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = A[i][2]+min(dp[i-1][1], dp[i-1][0]);
    }
    return min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
}
int main()
{
    vector<vector<int>>A ={{1, 2, 3},{10, 11, 12}}
    return bottomup(A);
}