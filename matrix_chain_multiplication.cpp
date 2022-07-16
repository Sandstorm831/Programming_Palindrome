/*
Given an array p[] which represents the chain of matrices such that the ith matrix Ai is of dimension p[i-1] x p[i].
We need to write a function MatrixChainOrder() that should return the minimum number of multiplications needed to multiply the chain. 

Input: p[] = {40, 20, 30, 10, 30}   
Output: 26000  
There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
Let the input 4 matrices be A, B, C and D.  The minimum number of 
multiplications are obtained by putting parenthesis in following way
(A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30
*/
#include <bits/stdc++.h>
using namespace std;
int recursor(vector<int> A, int i, int j,vector<vector<int>> dp)
{
    if(i>=j)
    {
        return 0;
    }
    if(dp[i][j] != -1) return dp[i][j];
    int minn = INT_MAX;
    for (int k = i; k <= j-1; k++)
    {
        int value = recursor(A, i, k, dp)+recursor(A,k+1,j, dp)+A[i-1]*A[k]*A[j];
        if(minn > value) minn = value;
    }
    return dp[i][j] = minn;
}
int mcm(vector<int> A)
{
    int n = A.size();
    int i = 1;
    int j = n-1;
    vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
    return recursor(A, i,j,dp);
}
int main()
{
    vector<int> A = {40, 20, 30, 10, 30};
    cout<<mcm(A);
}