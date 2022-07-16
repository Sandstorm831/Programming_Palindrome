/*
Given a value V, if we want to make a change for V cents, and we have an infinite supply of each of
C = { C1, C2, .., Cm} valued coins, what is the minimum number of coins to make the change? If it’s not possible to make a change, print -1.

Examples:  

Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required We can use one coin of 25 cents and one of 5 cents 

Input: coins[] = {9, 6, 5, 1}, V = 11
Output: Minimum 2 coins required We can use one coin of 6 cents and 1 coin of 5 cents
*/

#include <bits/stdc++.h>
using namespace std;
int changeCoin(vector<int> coins, int amount)
{
    int size = coins.size();
    vector<vector<int>> dp(size+1, vector<int> (amount+1));
    for (int i = 0; i < size+1; i++)
    {
        for (int j = 0; j < amount+1; j++)
        {
            if(i == 0) dp[i][j] = INT_MAX-1;
            else if(j == 0) dp[i][j]  = 0;
            else if(i==1)
            {
                if(j%coins[i-1] == 0) dp[i][j] = j/coins[i-1];
                else dp[i][j] = INT_MAX-1;
            }
            else if(coins[i-1]<=amount) dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    if(dp[size][amount] == INT_MAX-1) return -1;
    return dp[size][amount];
}
int main(){;
    vector<int> coins = {1,2,5}; //{186,419,83,408}
    int amount = 11;//6249;
    cout<<changeCoin(coins, amount);
}