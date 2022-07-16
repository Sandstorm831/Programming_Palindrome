/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1
 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
*/
#include <bits/stdc++.h>
using namespace std;
int target_sum(vector<int> A, int diff)
{
    int size = A.size();
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum+=A[i];
    }
    int sumfind = (sum+diff)/2;
    vector<vector<int>> dp(size+1, vector<int> (sumfind+1));
    for (int i = 0; i < size+1; i++)
    {
        for (int j = 0; j < sumfind+1; j++)
        {
            if(j == 0) dp[i][j] = 1;
            else if(i == 0) dp[i][j]  = 0;
            else if(A[i-1] > j) dp[i][j] = dp[i-1][j];
            else if(A[i-1] <= j) dp[i][j] = dp[i-1][j - A[i-1]] + dp[i-1][j];
        }
    }
    return dp[size][sumfind];
}
int main()
{
    vector<int> A = {1,1,2,3};
    int B = 1;
    cout<<target_sum(A,B);
}