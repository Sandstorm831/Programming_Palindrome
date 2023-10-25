// Question Link - https://leetcode.com/problems/student-attendance-record-ii/description/
// solution 

int mod = 1e9+7;
vector<vector<vector<int>>> dp(1e5+5, vector<vector<int>> (2, vector<int> (3, -1)));
class Solution {
public:
    int recursor(int n, int index, int absent, int late)
    {
        if(index == n-1)
        {
            if(absent == 0 && late<2) return 3;
            else if(absent == 0) return 2;
            else if(late < 2) return 2;
            else return 1;
        }
        else if(index >= n) return 0;
        else if(dp[n-index][absent][late] != -1) return dp[n-index][absent][late];
        else
        {
            int counter=0;
            if(absent == 0 && late<2)
            {
                counter = (counter%mod + recursor(n, index+1, absent+1, 0)%mod)%mod;
                counter = (counter%mod + recursor(n, index+1, absent, late+1)%mod)%mod;
                counter = (counter%mod + recursor(n, index+1, absent, 0)%mod)%mod;
            }
            else if(absent == 0)
            {
                counter = (counter%mod + recursor(n, index+1, absent+1, 0)%mod)%mod;
                counter = (counter%mod + recursor(n, index+1, absent, 0)%mod)%mod;
            }
            else if(late < 2)
            {
                counter = (counter%mod + recursor(n, index+1, absent, late+1)%mod)%mod;
                counter = (counter%mod + recursor(n, index+1, absent, 0)%mod)%mod;
            }
            else counter = (counter%mod + recursor(n, index+1, absent, 0)%mod)%mod;
            return dp[n-index][absent][late] = counter%mod;
        }
    }
    int checkRecord(int n) {
        return recursor(n,0,0,0)%mod;
    }
};