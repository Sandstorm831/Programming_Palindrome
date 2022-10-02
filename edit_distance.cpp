// Problem Link - https://www.interviewbit.com/problems/edit-distance/
/* Problem Solution
int recursor(string A, int index_a, string B, int index_b, vector<vector<int>>& dp)
{
    if(index_a >= A.length() && index_b >= B.length()) return 0;
    else if(index_a >= A.length()) return B.length()-index_b;
    else if(index_b>=B.length()) return A.length()-index_a;
    if(dp[index_a][index_b] != -1) return dp[index_a][index_b];
    if(A[index_a] == B[index_b]) return dp[index_a][index_b] = recursor(A, index_a+1, B, index_b+1, dp);
    else
    {
        return dp[index_a][index_b] = min(min(1+recursor(A, index_a+1, B, index_b, dp), 1+recursor(A, index_a, B, index_b+1, dp)), 1+recursor(A, index_a+1, B, index_b+1, dp));
    }
}
int Solution::minDistance(string A, string B) {
    int na = A.length();
    int nb = B.length();
    vector<vector<int>> dp(na+1, vector<int> (nb+1, -1));
    return recursor(A,0,B,0,dp);
}
*/
#include <bits/stdc++.h>
using namespace std;
int recursor(string A, int index_a, string B, int index_b, vector<vector<int>>& dp)
{
    if(index_a >= A.length() && index_b >= B.length()) return 0;
    else if(index_a >= A.length()) return B.length()-index_b;
    else if(index_b>=B.length()) return A.length()-index_a;
    if(dp[index_a][index_b] != -1) return dp[index_a][index_b];
    if(A[index_a] == B[index_b]) return dp[index_a][index_b] = recursor(A, index_a+1, B, index_b+1, dp);
    else
    {
        return dp[index_a][index_b] = min(min(1+recursor(A, index_a+1, B, index_b, dp), 1+recursor(A, index_a, B, index_b+1, dp)), 1+recursor(A, index_a+1, B, index_b+1, dp));
    }
}
int main()
{
    string A = "abacde";
    string B = "abcadlmn";
    int na = A.length();
    int nb = B.length();
    vector<vector<int>> dp(na+1, vector<int> (nb+1, -1));
    return recursor(A,0,B,0,dp);
}