// Question LINk - https://leetcode.com/problems/climbing-stairs/description/?envType=study-plan-v2&envId=dynamic-programming
// Solution 

class Solution {
public:
    vector<int> dp;
    int recursor(int curr, int steps)
    {
        if(curr>steps) return 0;
        else if(curr == steps || curr == steps-1) return 1;
        else if(dp[steps-curr] != -1) return dp[steps-curr];
        return dp[steps-curr] = recursor(curr+1, steps)+recursor(curr+2, steps);
    }
    int climbStairs(int n) {
        dp.clear();
        dp.resize(n+1, -1);
        return recursor(0, n);
    }
};
/*Both solutions are important*/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2; i<=n; i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};