// Problem Link - https://www.interviewbit.com/problems/increasing-path-in-matrix/
/* Problem Solution
int distance(vector<vector<int>> A)
{
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> dp(n, vector<int> (m, 0));
    dp[0][0]=1;
    for(int i=1; i<n; i++)
    {
        if(A[i][0]>A[i-1][0]) dp[i][0] = 1+dp[i-1][0];
        else break;
    }
    for(int i=1; i<m; i++)
    {
        if(A[0][i]>A[0][i-1] && dp[0][i-1]>0) dp[0][i]=1+dp[0][i-1];
        else break;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(A[i][j]>A[i-1][j] && A[i][j]>A[i][j-1] && (dp[i-1][j]>0 || dp[i][j-1]>0)) dp[i][j] = 1+max(dp[i-1][j], dp[i][j-1]);
            else if(A[i][j]>A[i-1][j] && dp[i-1][j] > 0) dp[i][j] = 1+dp[i-1][j];
            else if(A[i][j]>A[i][j-1] && dp[i][j-1]>0) dp[i][j] =  1+dp[i][j-1];
        }
    }
    if(dp[n-1][m-1]==0) return -1;
    return dp[n-1][m-1];    
}
int Solution::solve(vector<vector<int> > &A) {
    return distance(A);
}
*/
#include <bits/stdc++.h>
using namespace std;
int distance(vector<vector<int>> A)
{
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> dp(n, vector<int> (m, 0));
    dp[0][0]=1;
    for(int i=1; i<n; i++)
    {
        if(A[i][0]>A[i-1][0]) dp[i][0] = 1+dp[i-1][0];
        else break;
    }
    for(int i=1; i<m; i++)
    {
        if(A[0][i]>A[0][i-1] && dp[0][i-1]>0) dp[0][i]=1+dp[0][i-1];
        else break;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(A[i][j]>A[i-1][j] && A[i][j]>A[i][j-1] && (dp[i-1][j]>0 || dp[i][j-1]>0)) dp[i][j] = 1+max(dp[i-1][j], dp[i][j-1]);
            else if(A[i][j]>A[i-1][j] && dp[i-1][j] > 0) dp[i][j] = 1+dp[i-1][j];
            else if(A[i][j]>A[i][j-1] && dp[i][j-1]>0) dp[i][j] =  1+dp[i][j-1];
        }
    }
    if(dp[n-1][m-1]==0) return -1;
    return dp[n-1][m-1];    
}
int main()
{
    vector<vector<int>> A = {{1, 2, 3, 4},{2, 2, 3, 4},{3, 2, 3, 4},{4, 5, 6, 7}}
     cout<<distance(A);
}