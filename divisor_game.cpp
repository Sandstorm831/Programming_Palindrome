// Question Link - https://leetcode.com/problems/divisor-game/description/
// solution 

vector<vector<int>> dp(1001, vector<int> (3,-1));
class Solution {
public:
    bool recursor(int n, int p)
    {
        if(n == 0 || n == 1) return p == 2;
        else if(dp[n][p] != -1) return dp[n][p];
        else if(p == 1)
        {
            bool ans=false;
            for(int i=n-1; i>0; i--)
            {
                if(n%i == 0) ans |= recursor(n-i, 2);
            }
            return dp[n][p] = ans;
        }
        else if(p == 2)
        {
            bool ans = true;
            for(int i=n-1; i>0;i--)
            {
                if(n%i == 0) ans = recursor(n-i,1);
                if(!ans) return dp[n][p] = ans;
            }
            return dp[n][p] = ans;
        }
        return dp[n][p] = false;
    }
    bool divisorGame(int n) {
        return recursor(n, 1);
    }
};