//Problem Link - https://www.interviewbit.com/problems/maximum-size-square-sub-matrix/
/* Problem Solution
int maxer(vector<vector<int>> A)
{
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> dp(n, vector<int> (m));
    int maxx=INT_MIN;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i==0 || j==0) dp[i][j] = A[i][j];
            else
            {
                if(A[i][j]==1) dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
                else dp[i][j]=0;
            }
            maxx = max(maxx, dp[i][j]);
        }
    }
    return maxx*maxx;
}
int Solution::solve(vector<vector<int> > &A) {
    return maxer(A);
}
*/
#include <bits/stdc++.h>
using namespace std;
int maxer(vector<vector<int>> A)
{
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> dp(n, vector<int> (m));
    int maxx=INT_MIN;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i==0 || j==0) dp[i][j] = A[i][j];
            else
            {
                if(A[i][j]==1) dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
                else dp[i][j]=0;
            }
            maxx = max(maxx, dp[i][j]);
        }
    }
    return maxx*maxx;
}
int main()
{
    vector<vector<int>> A = {{0, 1, 1, 0, 1},{1, 1, 0, 1, 0},{0, 1, 1, 1, 0},{1, 1, 1, 1, 0},{1, 1, 1, 1, 1},{0, 0, 0, 0, 0}};
    cout<<maxer(A);
}