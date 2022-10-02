// Problem Link - https://www.interviewbit.com/problems/regular-expression-match/
/* Problem Solution
int expres(string target, string pattern)
{
    int t = target.length();
    int p = pattern.length();
    vector<vector<bool>> dp(t+1, vector<bool> (p+1));
    for(int i=0; i<=t; i++)
    {
        for(int j=0; j<=p; j++)
        {
            if(i==0&&j==0) dp[i][j]=1;
            else if(i==0 && j!=0 ) dp[i][j] = (dp[i][j-1] && pattern[j-1]=='*');
            else if(i!=0 && j==0) dp[i][j] = 0;
            else if(target[i-1]==pattern[j-1] || pattern[j-1] == '?') dp[i][j] = dp[i-1][j-1];
            else if(pattern[j-1] == '*') dp[i][j] = (dp[i-1][j]||dp[i][j-1]);
        }
    }
    return dp[t][p];
}
int Solution::isMatch(const string A, const string B) {
    return expres(A,B);
}
*/
#include <bits/stdc++.h>
using namespace std;
int expres(string target, string pattern)
{
    int t = target.length();
    int p = pattern.length();
    vector<vector<bool>> dp(t+1, vector<bool> (p+1));
    for(int i=0; i<=t; i++)
    {
        for(int j=0; j<=p; j++)
        {
            if(i==0&&j==0) dp[i][j]=1;
            else if(i==0 && j!=0 ) dp[i][j] = (dp[i][j-1] && pattern[j-1]=='*');
            else if(i!=0 && j==0) dp[i][j] = 0;
            else if(target[i-1]==pattern[j-1] || pattern[j-1] == '?') dp[i][j] = dp[i-1][j-1];
            else if(pattern[j-1] == '*') dp[i][j] = (dp[i-1][j]||dp[i][j-1]);
        }
    }
    return dp[t][p];
}
int main()
{
    string A = "agerfeorgin";
    string B = "*erf??*";
    cout<<expres(A, B);
}