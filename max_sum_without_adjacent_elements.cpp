// Problem Link - https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/
/*
int topdown(vector<vector<int>> A)
{
    int n = A[0].size();
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = max(A[0][0], A[1][0]);
    for(int i=2; i<=n;i++)
    {
        dp[i] = max(dp[i-1], dp[i-2]+max(A[0][i-1], A[1][i-1]));
    }
    return dp[n];
}
int Solution::adjacent(vector<vector<int> > &A) {
    return topdown(A);
}
*/
#include <bits/stdc++.h>
using namespace std; 
int topdown(vector<vector<int>> A)
{
    int n = A[0].size();
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = max(A[0][0], A[1][0]);
    for(int i=2; i<=n;i++)
    {
        dp[i] = max(dp[i-1], dp[i-2]+max(A[0][i-1], A[1][i-1]));
    }
    return dp[n];
}
int main()
{
    vector<vector<int>> A = {{1,2,3,4}, {2,3,4,5}};
    cout<<topdown(A);
}