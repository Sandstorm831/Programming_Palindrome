// Question Link - https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/
// Solution 

vector<vector<long long>> dp(501, vector<long long> (501, -1));
class Solution {
public:
    long long mod = 1e9+7;
    long long fact(long long x)
    {
        if(x == 0 || x==1) return 1;
        else return (x%mod)*(fact(x-1)%mod)%mod;
    }
    long long recursor(long long pairs, long long singles)
    {
        if(pairs == 1 && singles == 0) return 1;
        if(pairs == 0) return dp[pairs][singles] = fact(singles);
        else if(dp[pairs][singles] != -1) return dp[pairs][singles];
        else if(singles > 0 && pairs>0)
        {
            long long counter=0;
            counter = (counter%mod+ (((singles%mod)*(recursor(pairs, singles-1)%mod))%mod + ((pairs%mod)*(recursor(pairs-1, singles+1)%mod))%mod)%mod)%mod;
            return dp[pairs][singles] = counter;
        }
        else if(pairs > 0)
        {
            long long counter=0;
            counter = counter%mod+ ((pairs%mod)*(recursor(pairs-1, singles+1)%mod))%mod;
            return dp[pairs][singles] = counter;
        }
        return 0;
    }
    int countOrders(int n) {
        return recursor(n,0);
    }
};