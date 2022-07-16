// Problem Link - https://www.interviewbit.com/problems/longest-common-subsequence/
/* Complete Problem Solution
int recursor(string A, string B, int a, int b, vector<vector<int>>& dp) // Memoization+recursive approach
{
    if(a == 0 || b == 0) return dp[a][b] = 0;
    if(dp[a][b] != -1) return dp[a][b];
    if(A[a-1] == B[b-1]) return dp[a][b] = (1+recursor(A,B, a-1,b-1, dp));
    else return dp[a][b] = max(recursor(A,B, a-1,b, dp) , recursor(A,B,a,b-1, dp));
}
int lcs(string A, string B,int a,int b) // Bottom up approach
{
    vector<vector<int>> dp;
    dp.resize(a+1, vector<int> (b+1, -1));
    for(int i =0; i<=a; i++)
    {
        for(int j = 0; j<=b; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(A[i-1] == B[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j] ,dp[i][j-1]);
        }
    }
    return dp[a][b];
}
int Solution::solve(string A, string B) {
    int a = A.size();
    int b = B.size();
    vector<vector<int>> dp;
    dp.resize(a+1, vector<int> (b+1, -1));
    return recursor(A,B,a, b, dp); // Both of retrn statements
    return lcs(A,B,a, b);          // Give correct answer
}
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int recursor(string A, string B, int a, int b)
{
    if(a == 0 || b == 0) return 0;
    else if(dp[a][b] != -1) return dp[a][b];
    else if(A[a-1] == B[b-1]) return dp[a][b] = (1+recursor(A,B, a-1,b-1));
    else return dp[a][b] = max(recursor(A,B, a-1,b) , recursor(A,B,a,b-1));
}
int longestSubseq(string A, string B)
{
    int a = A.size();
    int b = B.size();
    dp.resize(a+1, vector<int> (b+1, -1));
    return recursor(A,B,a, b);
}
int lcs(string A, string B,int a,int b)
{
    vector<vector<int>> dp;
    dp.resize(a+1, vector<int> (b+1, -1));
    for(int i =0; i<=a; i++)
    {
        for(int j = 0; j<=b; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(A[i-1] == B[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j] ,dp[i][j-1]);
        }
    }
    return dp[a][b];
}
int main()
{
    string A = "abbcdgf";
    string B = "bbadcgf";
    int a = A.size();
    int b = B.size();
    cout<<longestSubseq(A, B)<<endl;
    cout<<lcs(A,B,a,b)<<endl;
}