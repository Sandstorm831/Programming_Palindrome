// Problem Link - https://www.interviewbit.com/problems/stairs/
/* Problem Solution
int counter(int A, vector<int> &dp)
{
    if(A==0) return 1;
    int noways=0;
    if(dp[A] != -1) return dp[A];
    if(A>=2) noways += counter(A-2, dp) + counter(A-1, dp);
    else if(A==1) noways += 1;
    return dp[A] = noways;
}
int Solution::climbStairs(int A) {
    vector<int> dp(A+1, -1);
    return counter(A, dp);
}
*/
#include <bits/stdc++.h>
using namespace std;
int counter(int A, vector<int> &dp)
{
    if(A==0) return 1;
    int noways=0;
    if(dp[A] != -1) return dp[A];
    if(A>=2) noways += counter(A-2, dp) + counter(A-1, dp);
    else if(A==1) noways += 1;
    return dp[A] = noways;
}
int main()
{
    int A = 18;
    vector<int> dp(A+1, -1);
    return counter(A, dp);
}