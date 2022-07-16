/*
Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if the length of the rod is 8 and the values of different pieces are given as the following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20
And if the prices are as following, then the maximum obtainable value is 24 (by cutting in eight pieces of length 1) 

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 3   5   8   9  10  17  17  20

*/
#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> lengths, vector<int> prices, int rod)
{
    int size = lengths.size();
    vector<vector<int>> dp(size+1, vector<int> (rod+1));
    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= rod; j++)
        {
            if(i ==0 || j == 0) dp[i][j] = 0;
            else if(lengths[i-1] <= j) dp[i][j] = max((prices[i-1]+dp[i][j-lengths[i-1]]), dp[i-1][j]);
            else if(lengths[i-1] > j) dp[i][j] = dp[i-1][j];
        }
    }
    return dp[size][rod];   
    
}
int main()
{
    vector<int> length = {1,2,3,4,5,6,7,8};
    vector<int> price = {1,5,8,9,10, 17,17,20};
    int rod_len = 8;
    cout<<maxProfit(length, price, rod_len);
}