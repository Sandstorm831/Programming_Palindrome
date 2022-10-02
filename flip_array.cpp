// Problem Link - https://www.interviewbit.com/problems/flip-array/
/* Problem Solution Function -------------------------------------------+
int bottomup(vector<int> A, int sum)            <-----------------------+
{  
    int n = A.size();
    vector<vector<int>> dp(n+1, vector<int> (sum+1));
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=sum; j++)
        {
            if(j==0) dp[i][j] = 0;
            else if(i==0) dp[i][j] = INT_MAX-1;
            else if(A[i-1]<=j) dp[i][j] = min(1+dp[i-1][j-A[i-1]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    for(int i=sum/2; i>=0; i--)
    {
        int minn = INT_MAX-1;
        for(int j=0; j<=n; j++)
        {
            minn = min(minn, dp[j][i]);
        }
        if(minn != INT_MAX-1) return minn;
    }
}
int Solution::solve(const vector<int> &A) {
    int sum=0;
    for(int i=0; i<A.size(); i++)
    {
        sum +=A[i];
    }
    int ans = bottomup(A, sum);
    return ans;
}
*/
#include <bits/stdc++.h>
using namespace std;
int bottomup(vector<int> A, int sum)
{
    int n = A.size();
    vector<vector<int>> dp(n+1, vector<int> (sum+1));
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=sum; j++)
        {
            if(j==0) dp[i][j] = 0;
            else if(i==0) dp[i][j] = INT_MAX-1;
            else if(A[i-1]<=j) dp[i][j] = min(1+dp[i-1][j-A[i-1]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    for(int i=sum/2; i>=0; i--)
    {
        int minn = INT_MAX-1;
        for(int j=0; j<=n; j++)
        {
            minn = min(minn, dp[j][i]);
        }
        if(minn != INT_MAX-1) return minn;
    }
}
int main()
{
    vector<int> A = {1,2,3,5,19,45};
    int sum=0;
    for(int i=0; i<A.size(); i++)
    {
        sum +=A[i];
    }
    int ans = bottomup(A, sum);
    return ans;
}