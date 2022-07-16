//Problem Link - https://www.interviewbit.com/problems/longest-palindromic-subsequence/
/*
Given a string A, find the common palindromic sequence ( A sequence which does not need to be contiguous and is a pallindrome), which is common in itself.

You need to return the length of longest palindromic subsequence in A.

NOTE:

Your code will be run on multiple test cases (<=10). Try to come up with an optimised solution.
// Solution 
int Solution::solve(string A) {
    string B = A;
    reverse(A.begin(), A.end());
    int a = A.size();
    int b = B.size();
    vector<vector<int>> dp(a+1, vector<int> (b+1));
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(A[i-1] == B[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[a][b];
}
*/
#include <bits/stdc++.h>
using namespace std;
int palindromeLength(string A)
{
        string B = A;
        reverse(A.begin(), A.end());
        int a = A.size();
        int b = B.size();
        vector<vector<int>> dp(a+1, vector<int> (b+1));
        for (int i = 0; i <= a; i++)
        {
            for (int j = 0; j <= b; j++)
            {
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(A[i-1] == B[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[a][b];
}
int main()
{
    string A = "agbcba";
    cout<<palindromeLength(A);
}