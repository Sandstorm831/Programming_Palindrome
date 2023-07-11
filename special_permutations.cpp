// QUestion Link - https://leetcode.com/problems/special-permutations/description
// Solution 

class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>> dp;
    int recursor(vector<int>& nums, int nos, int prev, int finder)
    {
        
        int ans = 0;
        if(nos == nums.size()) return 1;
        else if(dp[prev][finder] != -1) return dp[prev][finder];
        for(int i=0; i<nums.size(); i++)
        {
            if((finder & (1<<i)) == 0)
            {
                if(nums[i]%nums[prev] == 0 || nums[prev]%nums[i] == 0)
                {
                    ans = (ans%mod + recursor(nums, nos+1, i, (finder|1<<i))%mod)%mod;
                }
            }
        }
        return dp[prev][finder] = ans;
    }
    int specialPerm(vector<int>& nums) {
        dp.clear();
        dp.resize(15, vector<int> ((1<<15), -1));
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans = (ans%mod + (recursor(nums,1, i, 1<<i))%mod)%mod;
        }
        return ans;
    }
};

//// Another Approach

class Solution {
public:
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        int m = 1 << n;
        int dp[n+1][m+1];
        int mod = 1e9 + 7;
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = 0;
            }
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if ((j >> i) & 1) {
                    if (__builtin_popcount(j) == 1) {
                        dp[i][j] = 1;
                    }
                    else {
                        int k = j ^ (1 << i);
                        for (int l = 0; l < n; l++) {
                            if (((k >> l) & 1) and (nums[i] % nums[l] == 0 or nums[l] % nums[i] == 0)) {
                                dp[i][j] = (dp[i][j] + dp[l][k]) % mod;
                            }
                        }
                    }
                }
                if (__builtin_popcount(j) == n) {
                    ans = (ans + dp[i][j]) % mod;
                }
                //cout << i << " " << j << " " << dp[i][j] << '\n';
            }
        }
        return ans;
    }
};