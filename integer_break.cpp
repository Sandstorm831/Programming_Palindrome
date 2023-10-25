// Question Link - https://leetcode.com/problems/integer-break/description
// solution 

vector<int> dp(60, -1);
class Solution {
public:
    int recursor(int n)
    {
        cout<<n<<endl;
        if(n == 0 || n == 1) return 1;
        else if(n == 2) return 1;
        else if(dp[n] != -1) return dp[n];
        else
        {
            long long ans = INT_MIN;
            for(long long i=1; i<=n; i++)
            {
                ans = max(i*recursor(n-i), ans);
            }
            return dp[n] = int(ans);
        }
    }
    int integerBreak(int n) {
        if(n == 3) return 2;
        return recursor(n);
    }
};