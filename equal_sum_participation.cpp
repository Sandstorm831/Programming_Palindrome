// Problem Link - https://www.geeksforgeeks.org/partition-problem-dp-18/
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
bool equalsumpartition(vector<int> numbers)
{
    int sum = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        sum += numbers[i];
    }
    if(sum%2 != 0) return false;
    else return subsetsum(numbers, sum/2);
    
}
int main()
{
    vector<int> numbers = {1,2,5,3,11};
    cout<<equalsumpartition(numbers);
}