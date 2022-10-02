// Problem Link - https://www.interviewbit.com/problems/tiling-with-dominoes/
/* Problem Solution
int t = 1000000007;
vector<vector<int>>dp;
int recursorA(int);
int recursorB(int B)
{
    if(B==0) return 0;
    else if(B==1) return 1;
    if(dp[B][1] != -1) return dp[B][1];
    int ans;
    dp[B][1] = (recursorA(B-1)%t + recursorB(B-2)%t)%t;
    return dp[B][1];
}
int recursorA(int A)
{
    if(A==0) return 1;
    else if(A==1) return 0;
    if(dp[A][0] != -1) return dp[A][0];
    dp[A][0] = (recursorA(A-2)%t + (2*(recursorB(A-1)%t))%t)%t;
    return dp[A][0];
}
int Solution::solve(int A) {
    dp.resize(A+1, vector<int> (2,-1));
    if(A%2 == 1) return 0;
    return recursorA(A)%t;
}
*/
#include <bits/stdc++.h>
using namespace std;
int t = 1000000007;
vector<vector<int>>dp;
int recursorA(int);
int recursorB(int B)
{
    if(B==0) return 0;
    else if(B==1) return 1;
    if(dp[B][1] != -1) return dp[B][1];
    int ans;
    dp[B][1] = (recursorA(B-1)%t + recursorB(B-2)%t)%t;
    return dp[B][1];
}
int recursorA(int A)
{
    if(A==0) return 1;
    else if(A==1) return 0;
    if(dp[A][0] != -1) return dp[A][0];
    dp[A][0] = (recursorA(A-2)%t + (2*(recursorB(A-1)%t))%t)%t;
    return dp[A][0];
}
int main()
{
    int A = 5;
    dp.resize(A+1, vector<int> (2,-1));
    if(A%2 == 1) return 0;
    return recursorA(A)%t;
}