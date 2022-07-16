/*
Given a string, find the length of the longest repeating subsequence, such that the two subsequences
don’t have same string character at the same position, i.e. any ith character in the two subsequences
shouldn’t have the same index in the original string. 

Examples:

Input: str = "abc"
Output: 0
There is no repeating subsequence

Input: str = "aab"
Output: 1
The two subsequence are 'a'(first) and 'a'(second). 
Note that 'b' cannot be considered as part of subsequence 
as it would be at same index in both.

Input: str = "aabb"
Output: 2

Input: str = "axxxy"
Output: 2
*/
#include <bits/stdc++.h>
using namespace std;
int incSub(string A)
{
    int a = A.size();
    vector<vector<int>> dp(a+1, vector<int> (a+1));
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= a; j++)
        {
            if(i == 0 || j == 0)dp[i][j] = 0;
            else if(A[i-1] == A[j-1] && i != j) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[a][a];
}
int main()
{
    string A = "aabebcdd";
    cout<<incSub(A);
}