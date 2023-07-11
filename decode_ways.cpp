// Question LInk - https://leetcode.com/problems/decode-ways/description?envType=study-plan-v2&envId=dynamic-programming
// Solution 

class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        vector<int> dp(s.size()+1, 0);
        dp[0]=1;
        dp[1]=1;
        for(int i=1; i<s.size(); i++)
        {
            cout<<s[i]<<endl;
            if(s[i] != '0' && (s[i] - '0')<=6 && s[i-1]=='2')
            {
                dp[i+1] += dp[i]+dp[i-1];
            }
            else if(s[i] != '0' && s[i-1] == '1')
            {
                dp[i+1] += dp[i]+dp[i-1];
            }
            else if(s[i] != '0') dp[i+1]+= dp[i];
            else if(s[i] == '0' && (s[i-1] == '1' || s[i-1] == '2')) dp[i+1] += dp[i-1];
            else if(s[i] == '0') return 0;
        }
        return dp[s.size()];
    }
};