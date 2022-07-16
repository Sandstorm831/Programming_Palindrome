//Problem Link - https://www.interviewbit.com/problems/minimum-difference-subsets/
/* Complete Problem Solution --------------------------+
int sum;            <----------------------------------+
int minsubsetdifference(vector<int> vec)
{
    int size = vec.size();
    sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum+=vec[i];
    }
    vector<vector<bool>> dp(size+1,vector<bool> (sum+1));
    for (int i = 0; i < size+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(j == 0) dp[i][j] = true;
            else if(i == 0) dp[i][j] = false;
            else if(vec[i-1] > j) dp[i][j] = dp[i-1][j];
            else if(vec[i-1] <= j) dp[i][j] = dp[i-1][j-vec[i-1]]||dp[i-1][j];
        }
    }
    int maxy;
    for (int i = 0; i < (sum/2)+1; i++)
    {
        if(dp[size][i] == true) maxy = i;
    }
    return (sum)-2*maxy;
}
int Solution::solve(vector<int> &A) {
    return minsubsetdifference(A);
}
*/
#include <bits/stdc++.h>
using namespace std;
int sum;
int minsubsetdifference(vector<int> vec)
{
    int size = vec.size();
    sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum+=vec[i];
    }
    vector<vector<bool>> dp(size+1,vector<bool> (sum+1));
    for (int i = 0; i < size+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(j == 0) dp[i][j] = true;
            else if(i == 0) dp[i][j] = false;
            else if(vec[i-1] > j) dp[i][j] = dp[i-1][j];
            else if(vec[i-1] <= j) dp[i][j] = dp[i-1][j-vec[i-1]]||dp[i-1][j];
        }
    }
    int maxy;
    for (int i = 0; i < (sum/2)+1; i++)
    {
        if(dp[size][i] == true) maxy = i;
    }
    return (sum)-2*maxy;
}
int main()
{
    vector<int> A = {1,10,11,5};
    cout<<minsubsetdifference(A);
}