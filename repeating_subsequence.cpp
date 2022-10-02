// Problem Link - https://www.interviewbit.com/problems/repeating-subsequence/
/* Problem Solubion
int topdown(string A)
{
    int n = A.length();
    vector<vector<int>> dp(n+1, vector<int> (n+1));
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i == 0 || j==0) dp[i][j]=0;
            else if(A[i-1] == A[j-1] && i != j) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}
int Solution::anytwo(string A) {
    int x = topdown(A);
    if(x >= 2) return 1;
    else return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int topdown(string A)
{
    int n = A.length();
    vector<vector<int>> dp(n+1, vector<int> (n+1));
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i == 0 || j==0) dp[i][j]=0;
            else if(A[i-1] == A[j-1] && i != j) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}
int main()
{
    string A = "abaefesafeaabababaab";
    int x = topdown(A);
    if(x >= 2) return 1;
    else return 0;
}