/// Question Link - https://leetcode.com/problems/longest-arithmetic-subsequence/description
// Solution 

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int maxlen = INT_MIN;
        unordered_map<int,int> hash;
        vector<vector<int>> dp(n, vector<int> (n,2));
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n;j++)
            {
                int need = 2*nums[i]-nums[j];
                if(hash.find(need) != hash.end() && hash[need] < i)
                {
                    dp[i][j] = max(dp[i][j], dp[hash[need]][i]+1);
                }
                maxlen = max(maxlen, dp[i][j]);
            }
            hash[nums[i]]=i;
        }
        return maxlen;
    }
};