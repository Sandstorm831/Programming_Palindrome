// Problem Link - https://www.interviewbit.com/problems/min-sum-path-in-triangle/
/* Problem Solution ------------------------------------------+
int bottomup(vector<vector<int>> A)     <---------------------+
{
    int n = A.size()-1;
    vector<int> dp(n+1);
    for(int i=0; i<A[n].size(); i++)
    {
        dp[i]=A[n][i];
    }
    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<A[i].size(); j++)
        {
            dp[j] = A[i][j] + min(dp[j], dp[j+1]);
        }
    }
    return dp[0];
}
int Solution::minimumTotal(vector<vector<int> > &A) {
    return bottomup(A);
}
*/
#include <bits/stdc++.h>
using namespace std;
int bottomup(vector<vector<int>> A)
{
    int n = A.size()-1;
    vector<int> dp(n+1);
    for(int i=0; i<A[n].size(); i++)
    {
        dp[i]=A[n][i];
    }
    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<A[i].size(); j++)
        {
            dp[j] = A[i][j] + min(dp[j], dp[j+1]);
        }
    }
    return dp[0];
}
int main()
{
    vector<vector<int>> A = {{1}, {2,3}, {4,5,7}, {8,9,3,5}};
    cout<<bottomup(A);
}