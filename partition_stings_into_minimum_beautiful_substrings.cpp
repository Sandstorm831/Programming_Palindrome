// Question LInk - https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings/description/
// Solution 

class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        int n = s.length();
        vector<int> dp(n+1, n+1);
        dp[0]=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='0' || dp[i] > n) continue;
            for(int j=i, cur=0; j<n; j++)
            {
                cur  = cur*2+(s[j]-'0');
                if(15625%cur == 0)
                {
                    dp[j+1] = min(dp[i]+1, dp[j+1]);
                }
            }
        }
        if(dp[n]>n) return -1;
        return dp[n];
    }
};