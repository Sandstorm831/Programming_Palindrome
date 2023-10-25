// Question Link - https://leetcode.com/problems/coin-change-ii/description/
// solution 

class Solution {
public:
    vector<vector<int>> dp;
    int recursor(int amount, vector<int>& coins, int index)
    {
        if(amount == 0) return 1;
        else if(index < 0) return 0;
        else if(dp[amount][index] != -1) return dp[amount][index];
        else
        {
            if(coins[index] > amount) return dp[amount][index] = recursor(amount, coins,index-1);
            else
            {
                unsigned int count=0;
                count += recursor(amount-coins[index], coins, index);
                count += recursor(amount, coins, index-1);
                return dp[amount][index] = count;
            }
        }
    }
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        dp.clear();dp.resize(amount+1, vector<int> (coins.size()+1, -1));
        return recursor(amount, coins, coins.size()-1);
    }
};