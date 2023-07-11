// Question LInk - https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/?envType=study-plan-v2&envId=dynamic-programming
// Solution 

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<pair<int,int>>> dp(s1.size()+1, vector<pair<int,int>> (s2.size()+1,make_pair(0,0)));
        for(int i=1; i<=s1.size(); i++)
        {
            for(int j=1; j<=s2.size(); j++)
            {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j].first = 1+dp[i-1][j-1].first;
                    dp[i][j].second = s1[i-1]+dp[i-1][j-1].second;
                }
                else
                {
                    int x = dp[i-1][j].first;
                    int y = dp[i][j-1].first;
                    if(x != y)
                    {
                        if(x>y)
                        {
                            dp[i][j].first = x;
                            dp[i][j].second = dp[i-1][j].second;
                        }
                        else
                        {
                            dp[i][j].first = y;
                            dp[i][j].second = dp[i][j-1].second;
                        }
                    }
                    else
                    {
                        dp[i][j].first = x;
                        dp[i][j].second = max(dp[i][j-1].second, dp[i-1][j].second);
                    }
                }
            }
        }
        int n1=0, n2=0;
        for(int i=0; i<s1.size(); i++)
        {
            n1 += s1[i];
        }
        for(int i=0; i<s2.size(); i++)
        {
            n2 += s2[i];
        }
        return n1+n2-2*dp[s1.size()][s2.size()].second;
    }
};