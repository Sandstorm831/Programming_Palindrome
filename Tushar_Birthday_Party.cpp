// Problem Link - https://www.interviewbit.com/problems/tushars-birthday-party/
/* Problem Solution
int topdown(int frnd,vector<int> A, vector<int> B, vector<int> C, int sutter)  // unordered_map<int,int> mapy)
{
    int n = B.size();
    vector<vector<int>> dp(frnd+1, vector<int> (n+1));
    for(int i=0; i<=frnd; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i == 0) dp[i][j] = 0;
            else if(j == 0) dp[i][j] = INT_MAX-sutter;
            else if(B[j-1]<=i) dp[i][j] = min(C[j-1]+dp[i-B[j-1]][j], dp[i][j-1]);
            else dp[i][j] = dp[i][j-1];
        }
    }
    int cost=0;
    for(int i=0; i<A.size(); i++)
    {
        cost += dp[A[i]][n];
    }
    return cost;
}
int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int maxu = INT_MIN;
    int maxy = INT_MIN;
    for(int i=0; i<A.size(); i++)
    {
        maxu = max(maxu, A[i]);
    }
    for(int i=0; i<B.size(); i++)
    {
        maxy = max(maxy, C[i]);
    }
    return topdown(maxu, A,B,C, maxy);
}
*/
#include <bits/stdc++.h>
using namespace std;
int topdown(int frnd,vector<int> A, vector<int> B, vector<int> C, int sutter)  // unordered_map<int,int> mapy)
{
    int n = B.size();
    vector<vector<int>> dp(frnd+1, vector<int> (n+1));
    for(int i=0; i<=frnd; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i == 0) dp[i][j] = 0;
            else if(j == 0) dp[i][j] = INT_MAX-sutter;
            else if(B[j-1]<=i) dp[i][j] = min(C[j-1]+dp[i-B[j-1]][j], dp[i][j-1]);
            else dp[i][j] = dp[i][j-1];
        }
    }
    int cost=0;
    for(int i=0; i<A.size(); i++)
    {
        cost += dp[A[i]][n];
    }
    return cost;
}
int main()
{
    vector<int> A = {4,6};
    vector<int> B = {1,3};
    vector<int> C = {5,3};
    int maxu = INT_MIN;
    int maxy = INT_MIN;
    for(int i=0; i<A.size(); i++)
    {
        maxu = max(maxu, A[i]);
    }
    for(int i=0; i<B.size(); i++)
    {
        maxy = max(maxy, C[i]);
    }
    cout<<topdown(maxu, A,B,C, maxy);
}