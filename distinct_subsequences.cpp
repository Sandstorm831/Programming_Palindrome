// Problem Link - https://www.interviewbit.com/problems/distinct-subsequences/
/*
int distinctor(string A, string B)
{
    int a = A.length();
    int b = B.length();
    vector<vector<int>> dp(b+1, vector<int> (a+1,0));
    for(int i=0; i<=b; i++)
    {
        for(int j=i; j<=a; j++)
        {
            if(i==0) dp[i][j]=1;
            else if(A[j-1]==B[i-1]) dp[i][j] = dp[i-1][j-1]+dp[i][j-1];
            else dp[i][j] = dp[i][j-1];
        }
    }
    return dp[b][a];
}
int Solution::numDistinct(string A, string B) {
    return distinctor(A, B);
}
*/
#include <bits/stdc++.h>
using namespace std;
int distinctor(string A, string B)
{
    int a = A.length();
    int b = B.length();
    vector<vector<int>> dp(b+1, vector<int> (a+1,0));
    for(int i=0; i<=b; i++)
    {
        for(int j=i; j<=a; j++)
        {
            if(i==0) dp[i][j]=1;
            else if(A[j-1]==B[i-1]) dp[i][j] = dp[i-1][j-1]+dp[i][j-1];
            else dp[i][j] = dp[i][j-1];
        }
    }
    return dp[b][a];
}
int main()
{
    string A = "rabbbit";
    string B = "rabbit"
    return distinctor(A, B);
}