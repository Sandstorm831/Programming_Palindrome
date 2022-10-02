/* Problem Link - https://www.interviewbit.com/problems/kingdom-war/
int powerloss(vector<vector<int>> A)
{
    int maxx = INT_MIN;
    int n=A.size();
    int m = A[0].size();
    vector<vector<int>> dp(n, vector<int> (m));
    dp[n-1][m-1]=A[n-1][m-1];
    maxx = dp[n-1][m-1];
    for(int i=n-2; i>=0; i--)
    {
        dp[i][m-1] = A[i][m-1]+dp[i+1][m-1];
        maxx = max(maxx, dp[i][m-1]);
    }
    for(int i=m-2; i>=0; i--)
    {
        dp[n-1][i] = A[n-1][i]+dp[n-1][i+1];
        maxx = max(maxx, dp[n-1][i]);
    }
    for(int i=n-2; i>=0; i--)
    {
        for(int j=m-2; j>=0; j--)
        {
            dp[i][j] = dp[i+1][j]+dp[i][j+1]-dp[i+1][j+1]+A[i][j];
            maxx = max(maxx, dp[i][j]);
        }
    }
    return maxx;
}
int Solution::solve(vector<vector<int> > &A) {
    return powerloss(A);
}
*/
#include <bits/stdc++.h>
using namespace std;
int powerloss(vector<vector<int>> A)
{
    int maxx = INT_MIN;
    int n=A.size();
    int m = A[0].size();
    vector<vector<int>> dp(n, vector<int> (m));
    dp[n-1][m-1]=A[n-1][m-1];
    maxx = dp[n-1][m-1];
    for(int i=n-2; i>=0; i--)
    {
        dp[i][m-1] = A[i][m-1]+dp[i+1][m-1];
        maxx = max(maxx, dp[i][m-1]);
    }
    for(int i=m-2; i>=0; i--)
    {
        dp[n-1][i] = A[n-1][i]+dp[n-1][i+1];
        maxx = max(maxx, dp[n-1][i]);
    }
    for(int i=n-2; i>=0; i--)
    {
        for(int j=m-2; j>=0; j--)
        {
            dp[i][j] = dp[i+1][j]+dp[i][j+1]-dp[i+1][j+1]+A[i][j];
            maxx = max(maxx, dp[i][j]);
        }
    }
    return maxx;
}
int main()
{
    vector<vector<int>> A = {{-5,-4,-1}, {-3,2,4}, {2,5,8}};
    cout<<powerloss(A);
}