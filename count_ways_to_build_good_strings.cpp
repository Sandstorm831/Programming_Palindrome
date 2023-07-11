// Question Link - https://leetcode.com/problems/count-ways-to-build-good-strings/description?envType=study-plan-v2&envId=dynamic-programming
// Solution 

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, 0);
        dp[0]=1;
        int mod = 1e9+7;
        for(int i=1; i<=high; i++)
        {
            if(i-zero>=0) dp[i] = (dp[i]%mod + dp[i-zero]%mod)%mod;
            if(i-one >= 0) dp[i] = (dp[i]%mod + dp[i-one]%mod)%mod;
        }
        int summer=0;
        for(int i=low; i<=high; i++) summer=(summer%mod + dp[i]%mod)%mod;
        return summer;
    }
};