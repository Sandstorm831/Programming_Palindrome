// Question Link - https://leetcode.com/problems/count-numbers-with-unique-digits/description/
// solution 

vector<int> dp(10,-1);
class Solution {
public:
    int finder(int x)
    {
        int i = 9;
        int counter = 9;
        x--;
        while(x-- > 0)
        {
            counter = counter*i;
            i--;
        }
        return counter;
    }
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        dp[1] = 10;dp[2] = 81;
        int counter = 0;
        for(int i=1; i<=n; i++)
        {
            if(dp[i] != -1) counter += dp[i];
            else
            {
                dp[i] = finder(i);
                counter += dp[i];
            }
        }
        return counter;
    }
};