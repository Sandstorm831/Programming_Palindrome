// Problem Link - https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/
#include <bits/stdc++.h>
using namespace std;
int countingsubsetsum(vector<int> vec, int sum)
{
    int size = vec.size();
    vector<vector<int>> dp(size+1, vector<int> (sum+1));
    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if(j == 0) dp[i][j] = 1;
            else if(i == 0) dp[i][j] = 0;
            else if(vec[i-1] > j) dp[i][j] = dp[i-1][j];
            else if(vec[i-1] <= j) dp[i][j] = dp[i-1][j] + dp[i-1][j-vec[i-1]];
        }
    }
    return dp[size][sum];    
}
int main()
{
    vector<int> A = {3,3,3,3};
    int B = 6;
    cout<<countingsubsetsum(A, B);
}