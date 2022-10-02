// Problem Link - https://www.interviewbit.com/problems/dungeon-princess/
/*
int health(vector<vector<int>> A)
{
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> dp(n, vector<int> (m));
    if(A[n-1][m-1]<0) dp[n-1][m-1] = abs(A[n-1][m-1])+1;
    else dp[n-1][m-1]=1;
    for(int i=n-2; i>=0; i--)
    {
        dp[i][m-1] = dp[i+1][m-1]-A[i][m-1];
        if(dp[i][m-1]<=0) dp[i][m-1]=1;
    }
    for(int i=m-2; i>=0; i--)
    {
        dp[n-1][i] = dp[n-1][i+1]-A[n-1][i];
        if(dp[n-1][i] <=0) dp[n-1][i]=1;
    }
    for(int i=n-2; i>=0; i--)
    {
        for(int j=m-2; j>=0; j--)
        {
            dp[i][j] = min(dp[i+1][j], dp[i][j+1])-A[i][j];
            if(dp[i][j]<=0) dp[i][j]=1;
        }
    }
    return dp[0][0];
}
int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    return health(A);
}
*/
#include <bits/stdc++.h>
using namespace std;
int health(vector<vector<int>> A)
{
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> dp(n, vector<int> (m));
    if(A[n-1][m-1]<0) dp[n-1][m-1] = abs(A[n-1][m-1])+1;
    else dp[n-1][m-1]=1;
    for(int i=n-2; i>=0; i--)
    {
        dp[i][m-1] = dp[i+1][m-1]-A[i][m-1];
        if(dp[i][m-1]<=0) dp[i][m-1]=1;
    }
    for(int i=m-2; i>=0; i--)
    {
        dp[n-1][i] = dp[n-1][i+1]-A[n-1][i];
        if(dp[n-1][i] <=0) dp[n-1][i]=1;
    }
    for(int i=n-2; i>=0; i--)
    {
        for(int j=m-2; j>=0; j--)
        {
            dp[i][j] = min(dp[i+1][j], dp[i][j+1])-A[i][j];
            if(dp[i][j]<=0) dp[i][j]=1;
        }
    }
    return dp[0][0];
}
int main()
{
    vector<vector<int>> A = {{-2,-2,3}, {-5,-10,1}, {10,30,5}};
    cout<<health(A);
}