// Question Link - https://leetcode.com/problems/count-stepping-numbers-in-range/description/
// solution 

vector<vector<int>> dp(101, vector<int> (10, 0));
int mod = 1e9+7;
class Solution {
public:
    int dfs(int i, int p, const string &n, bool lim) {
        if (p < 0 || p > 9 || (lim && p > (n[n.size() - i] - '0'))) return 0;
        if (i == 1) return 1;    
        lim &= p == (n[n.size() - i] - '0');
        if (lim) return (dfs(i - 1, p - 1, n, lim) + dfs(i - 1, p + 1, n, lim)) % mod;
        if (dp[i][p] == 0) 
        {
            dp[i][p] = (1 + dfs(i - 1, p - 1, n, lim) + dfs(i - 1, p + 1, n, lim)) % mod;
        }
        return dp[i][p] - 1;
    }
    int count(const string &n) {
        int res = 0;
        for (int sz = 1; sz <= n.size(); ++sz)
        {
            for (int d = 1; d <= 9; ++d)
            {
                res = (res + dfs(sz, d, n, sz == n.size())) % mod; 
                cout<<sz<<" "<<d<<" "<<(sz == n.size())<<" "<<res<<endl;  
            }
        }
        return res;
    }
    int countSteppingNumbers(const string &low, const string &high) {
        int kk = 1;
        for(int i=1; i<low.size(); i++) if(abs(low[i] - low[i-1]) != 1) {kk=0;break;}
        return (mod + count(high) - count(low) + kk) % mod;
    }
};