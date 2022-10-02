/*
Problem Link - https://www.interviewbit.com/problems/merge-elements/
vector<vector<int>> dp;
vector<int> pre;
int recursor(vector<int> A, int i, int j)
{
    if(i==j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=i; k<j; k++)
    {
        
        ans=min(ans, recursor(A, i, k)+recursor(A, k+1, j)+pre[j+1]-pre[i]);
    }
    return dp[i][j] = ans;
}
int topdown(vector<int> A)
{
    int a = A.size();
    dp.clear();
    dp.resize(a, vector<int> (a, -1));
    pre.clear();
    int summ=0;
    pre.push_back(summ);
    for(int i=0; i<a; i++)
    {
        summ+=A[i];
        pre.push_back(summ);
    }
    return recursor(A, 0, a-1);
}
int Solution::solve(vector<int> &A) {
    return topdown(A);
}
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
vector<int> pre;
int recursor(vector<int> A, int i, int j)
{
    if(i==j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=i; k<j; k++)
    {
        
        ans=min(ans, recursor(A, i, k)+recursor(A, k+1, j)+pre[j+1]-pre[i]);
    }
    return dp[i][j] = ans;
}
int topdown(vector<int> A)
{
    int a = A.size();
    dp.clear();
    dp.resize(a, vector<int> (a, -1));
    pre.clear();
    int summ=0;
    pre.push_back(summ);
    for(int i=0; i<a; i++)
    {
        summ+=A[i];
        pre.push_back(summ);
    }
    return recursor(A, 0, a-1);
}
int main()
{
    vector<int> A = {1,2,3,4};
    return topdown(A);
}