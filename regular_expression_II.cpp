// Problem Link - https://www.interviewbit.com/problems/regular-expression-ii/hints/
/* Problem Solution
int anxer(string A, string B)
{
    int a = A.size();
    int b = B.size();
    vector<vector<bool>> dp(a+1, vector<bool> (b+1));
    for(int i=0; i<=a; i++)
    {
        for(int j=0; j<=b; j++)
        {
            if(i==0 && j==0) dp[i][j]=1;
            else if(j==0) dp[i][j]=0;
            else if(i==0 && j%2==1) dp[i][j] = 0;
            else if(i==0 && B[j-1] == '*') dp[i][j] = 1;
            else if(i==0) dp[i][j] == 0;
            else if(A[i-1] == B[j-1] || B[j-1] == '.') dp[i][j] = dp[i-1][j-1];
            else if(B[j-1] == '*')
            {
                if(B[j-2] == A[i-1] || B[j-2] == '.') dp[i][j] = dp[i-1][j];
                dp[i][j] = (dp[i][j]||dp[i][j-2]);
            }
            else dp[i][j]=0;
        }
    }
    return dp[a][b];
}
int Solution::isMatch(const string A, const string B) {
    return anxer(A, B);
}
*/
#include <bits/stdc++.h>
using namespace std;
int anxer(string A, string B)
{
    int a = A.size();
    int b = B.size();
    vector<vector<bool>> dp(a+1, vector<bool> (b+1));
    for(int i=0; i<=a; i++)
    {
        for(int j=0; j<=b; j++)
        {
            if(i==0 && j==0) dp[i][j]=1;
            else if(j==0) dp[i][j]=0;
            else if(i==0 && j%2==1) dp[i][j] = 0;
            else if(i==0 && B[j-1] == '*') dp[i][j] = 1;
            else if(i==0) dp[i][j] == 0;
            else if(A[i-1] == B[j-1] || B[j-1] == '.') dp[i][j] = dp[i-1][j-1];
            else if(B[j-1] == '*')
            {
                if(B[j-2] == A[i-1] || B[j-2] == '.') dp[i][j] = dp[i-1][j];
                dp[i][j] = (dp[i][j]||dp[i][j-2]);
            }
            else dp[i][j]=0;
        }
    }
    return dp[a][b];
}
int main()
{
    string A = "abcbcd";
    string B = "a.*b.*d";
    cout<<mixer(A,B);
}