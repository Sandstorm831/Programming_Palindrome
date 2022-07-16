// Problem Link - https://www.interviewbit.com/problems/0-1-knapsack/
/*Problem Solution Function memoize -----------------------------------------------------------------------------------------------+
int recursor(vector<int> weights, vector<int> values, int limiter, int size, vector<vector<int>>& dp)       <----------------------+
{
    if(size == 0 ) return 0;
    if(dp[limiter][size-1] != -1) return dp[limiter][size-1];
    if(weights[size-1] > limiter) return dp[limiter][size-1] = recursor(weights, values, limiter, size-1, dp);
    else return dp[limiter][size-1] = max((values[size-1]+recursor(weights, values, limiter-weights[size-1], size-1, dp)), recursor(weights, values, limiter, size-1, dp));
}
int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int size = A.size();
    vector<vector<int>> dp(C+1, vector<int> (size, -1));
    return recursor(B,A, C, size, dp);
}

Problem Solution Function Bottomup ----------------------------------------------------- +
.                                                                                        |
int topdown(vector<int> weights, vector<int> values, int limiter, int size)     <--------+
{
    vector<vector<int>> dp(limiter+1, vector<int> (size+1));
    for(int i = 0; i<limiter+1; i++)
    {
        for (int j = 0; j < size+1; j++)
        {
            if(i == 0 || j == 0) dp[i][j] == 0;
            else if(weights[j-1] <= i) dp[i][j] = max((values[j-1]+dp[i-weights[j-1]][j-1]), dp[i][j-1]);
            else dp[i][j] = dp[i][j-1];
        }    
    }
    return dp[limiter][size];
}
int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int size = A.size();
    return topdown(B, A, C, size);
}
*/
#include <bits/stdc++.h>
using namespace std;
int recursor(vector<int> weights, vector<int> values, int limiter, int size, vector<vector<int>>& dp)
{
    if(size == 0 ) return 0;
    if(dp[limiter][size-1] != -1) return dp[limiter][size-1];
    if(weights[size-1] > limiter) return dp[limiter][size-1] = recursor(weights, values, limiter, size-1, dp);
    else return dp[limiter][size-1] = max((values[size-1]+recursor(weights, values, limiter-weights[size-1], size-1, dp)), recursor(weights, values, limiter, size-1, dp));
}
int topdown(vector<int> weights, vector<int> values, int limiter, int size)
{
    vector<vector<int>> dp(limiter+1, vector<int> (size+1));
    for(int i = 0; i<limiter+1; i++)
    {
        for (int j = 0; j < size+1; j++)
        {
            if(i == 0 || j == 0) dp[i][j] == 0;
            else if(weights[j-1] <= i) dp[i][j] = max((values[j-1]+dp[i-weights[j-1]][j-1]), dp[i][j-1]);
            else dp[i][j] = dp[i][j-1];
        }    
    }
    return dp[limiter][size];
}

int knapsackmemoize(vector<int> &A, vector<int> &B, int C) {
    int size = A.size();
    vector<vector<int>> dp(C+1, vector<int> (size+1, -1));
    return recursor(B,A, C, size, dp);
}
int knapsacktopdown(vector<int> &A, vector<int> &B, int C) {
    int size = A.size();
    // vector<vector<int>> dp(C+1, vector<int> (size+1));
    return topdown(B, A, C, size);
}
int main()
{
    vector<int> weights = {256, 424, 3, 86, 183, 286, 89, 427, 118, 258, 333, 433, 170, 155, 222, 190, 477, 330, 369, 193, 426, 56, 435, 50, 442, 13, 146, 61, 219 };
    vector<int> values = {647, 363, 887, 876, 434, 870, 143, 845, 417, 882, 999, 323, 652, 22, 700, 558, 477, 893, 390, 76, 713, 601, 511, 4, 870, 862, 689, 402, 790};
    int threshold = 754;
    cout<<knapsacktopdown(values, weights, threshold)<<" ";
    cout<<knapsackmemoize(values, weights, threshold);
}