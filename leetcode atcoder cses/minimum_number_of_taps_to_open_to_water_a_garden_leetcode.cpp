// Question lINk - https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/
// solution 

class Solution {
public:
    int minnTaps(int n, vector<int>& ranges) {
        vector<int> gar(n+1, 0);
        for(int i=0; i<ranges.size(); i++)
        {
            gar[max(0,i-ranges[i])] = max(gar[max(0,i-ranges[i])], min(n, i+ranges[i]));
        }
        int taps=0;
        int curf = 0,finf=0;
        for(int i=0; i<=n; i++)
        {
            if(i>finf) return -1;
            else if(i>curf)
            {
                taps++;
                curf = finf;
            }
            finf = max(finf, gar[i]);
        }
        return taps;
    }
    int minTaps(int n, vector<int>& ranges)
    {
        vector<int> dp(n+1,n+2);
        dp[0]=0;
        for(int i=0; i<=n; i++)
        {
            for(int j=max(0,i-ranges[i]+1); j<min(n+1, ranges[i]+i+1); j++)
            {
                dp[j] = min(dp[j], 1+dp[max(0,i-ranges[i])]);
            }
        }
        return dp[n]>=n+2?-1:dp[n];
    }
}; 