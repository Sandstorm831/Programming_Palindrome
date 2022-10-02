// Problem Link - https://www.interviewbit.com/problems/interleaving-strings/
/* Problem Solution Function
int lcs(string A, string B)
{
    int a = A.size();
    int b = B.size();
    vector<vector<int>> dp(a+1, vector<int> (b+1));
    for(int i=0; i<=a; i++)
    {
        for(int j=0; j<=b; j++)
        {
            if(i==0 || j==0) dp[i][j] = 0;
            else if(A[i-1] == B[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[a][b];
}
int Solution::isInterleave(string A, string B, string C) {
    int a = lcs(A, C);
    int b = lcs(B,C);
    if(a == A.size() && b == B.size()) return 1;
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int lcs(string A, string B)
{
    int a = A.size();
    int b = B.size();
    vector<vector<int>> dp(a+1, vector<int> (b+1));
    for(int i=0; i<=a; i++)
    {
        for(int j=0; j<=b; j++)
        {
            if(i==0 || j==0) dp[i][j] = 0;
            else if(A[i-1] == B[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[a][b];
}
int main(){
    string A = "aabcc"
    string B = "dbbca"
    string C = "aadbbcbcac"
    int a = lcs(A, C);
    int b = lcs(B,C);
    if(a == A.size() && b == B.size()) return 1;
    return 0;
}