// Problem Link - https://www.interviewbit.com/problems/subset-sum-problem/
/* Problem Solution Function ---------------------------------+
int Solution::solve(vector<int> &A, int B) {        <---------+
    int size = A.size();
    vector<vector<bool>> dp(size+1, vector<bool> (B+1));
    for (int i = 0; i < size+1; i++)
    {
        for (int j = 0; j < B+1; j++)
        {
            if(i==0 && j==0) dp[i][j] = true;
            else if(j == 0) dp[i][j] = true;
            else if(i == 0) dp[i][j] = false;
            else if(A[i-1] > j) dp[i][j] = dp[i-1][j];
            else if(A[i-1] <= j) dp[i][j] = (dp[i-1][j-A[i-1]] || dp[i-1][j]);
        }
    }
    return dp[size][B];
}
*/
#include <bits/stdc++.h>
using namespace std;
bool subsetsum(vector<int> inty, int sum)
{
    int size = inty.size();
    vector<vector<bool>> dp(size+1, vector<bool> (sum+1));
    for (int i = 0; i < size+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(i==0 && j==0) dp[i][j] = true;
            else if(j == 0) dp[i][j] = true;
            else if(i == 0) dp[i][j] = false;
            else if(inty[i-1] > j) dp[i][j] = dp[i-1][j];
            else if(inty[i-1] <= j) dp[i][j] = (dp[i-1][j-inty[i-1]] || dp[i-1][j]);
        }
    }
    return dp[size][sum];
}
int main()
{
    vector<int> inty = {1,3,5,8,10};
    int sum = 30;
    cout<<subsetsum(inty, sum);
}