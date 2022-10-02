// Problem Link - https://www.interviewbit.com/problems/unique-paths-in-a-grid/
/* Problem Solution
int ans=0;
vector<vector<int>> dp;
int recursor(vector<vector<int>> A, int n, int m, int sn, int sm)
{
    if(n==sn && m==sm)
    {
        ans++;
        return 1;
    }
    else if(n==sn)
    {
        if(A[n][m+1]!=1) return recursor(A, n, m+1, sn, sm);
        return 0;
    }
    else if(m==sm)
    {
        if(A[n+1][m]!=1) return recursor(A, n+1, m, sn, sm);
        return 0;
    }
    if(dp[n][m]!=-1) return dp[n][m];
    if(A[n][m+1] != 1 && A[n+1][m] != 1) return dp[n][m] = recursor(A, n+1, m, sn, sm)+recursor(A, n, m+1, sn, sm);
    else if(A[n][m+1]!=1) return dp[n][m] = recursor(A, n, m+1, sn, sm);
    else if(A[n+1][m]!=1) return dp[n][m] = recursor(A, n+1, m, sn, sm);
    else return dp[n][m]=0;
}
int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    if(A[0][0]==1)return 0;
    int n=A.size(); 
    int m = A[0].size();
    dp.clear();
    dp.resize(n+1, vector<int> (m+1,-1));
    return recursor(A, 0, 0, n-1, m-1);
}
*/
#include <bits/stdc++.h>
using namespace std;
int ans=0;
vector<vector<int>> dp;
int recursor(vector<vector<int>> A, int n, int m, int sn, int sm)
{
    if(n==sn && m==sm)
    {
        ans++;
        return 1;
    }
    else if(n==sn)
    {
        if(A[n][m+1]!=1) return recursor(A, n, m+1, sn, sm);
        return 0;
    }
    else if(m==sm)
    {
        if(A[n+1][m]!=1) return recursor(A, n+1, m, sn, sm);
        return 0;
    }
    if(dp[n][m]!=-1) return dp[n][m];
    if(A[n][m+1] != 1 && A[n+1][m] != 1) return dp[n][m] = recursor(A, n+1, m, sn, sm)+recursor(A, n, m+1, sn, sm);
    else if(A[n][m+1]!=1) return dp[n][m] = recursor(A, n, m+1, sn, sm);
    else if(A[n+1][m]!=1) return dp[n][m] = recursor(A, n+1, m, sn, sm);
    else return dp[n][m]=0;
}
int main()
{
    vector<vector<int>> A = {{0,0,0}, {0,1,0},{0,0,0}};
    if(A[0][0]==1)return 0;
    int n=A.size(); 
    int m = A[0].size();
    dp.clear();
    dp.resize(n+1, vector<int> (m+1,-1));
    cout<<recursor(A, 0, 0, n-1, m-1);
}