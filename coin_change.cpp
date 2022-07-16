// Problem Link - https://leetcode.com/problems/coin-change-2/
/* Complete Problem Solution
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int size = coins.size();
    
        vector<vector<int>> dp(size+1, vector<int> (amount+1));
        for (int i = 0; i <= size; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                if(j == 0) dp[i][j] = 1;
                else if(i == 0) dp[i][j] = 0;
                else if(coins[i-1] <= j) dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                else if(coins[i-1] > j) dp[i][j] = dp[i-1][j];
            }
        }
        return dp[size][amount]; 
    }
};
*/
#include <bits/stdc++.h>
using namespace std;
int coinChange(vector<int> coins, int sum)
{
    int size = coins.size();
    vector<vector<int>> dp(size+1, vector<int> (sum+1));
    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if(j == 0) dp[i][j] = 1;
            else if(i == 0) dp[i][j] = 0;
            else if(coins[i-1] <= j) dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            else if(coins[i-1] > j) dp[i][j] = dp[i-1][j];
        }
    }
    return dp[size][sum];
}
int main()
{
    vector<int> coins = {2};
    int sum = 3;
    cout<<coinChange(coins, sum);
}