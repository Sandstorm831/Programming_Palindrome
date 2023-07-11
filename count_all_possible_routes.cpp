// Questoin LInk - https://leetcode.com/problems/count-all-possible-routes/description/
// Solution 

class Solution {
public:
    const int mod=1e9+7;
    vector<vector<int>> dp;
    int recursor(vector<int>& locations, int fuel, int node, int finish)
    {
        if(fuel == 0)
        {
            if(node==finish) return 1;
            else return 0;
        }
        else if(dp[node][fuel] != -1) return dp[node][fuel]%mod;
        else
        {
            int ans = 0;
            if(node == finish) ans++;
            for(int i=0; i<locations.size();i++)
            {
                if(i != node)
                {
                    if(abs(locations[i]-locations[node])<=fuel)
                    {
                        ans = (ans%mod + recursor(locations, fuel-abs(locations[i]-locations[node]), i,finish)%mod)%mod;
                    }
                }
            }
            return dp[node][fuel] = ans%mod;
        }
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int cur = start;
        int curf = fuel;
        dp.clear();
        dp.resize(locations.size()+1, vector<int> (fuel+1,-1));
        return recursor(locations, curf, cur, finish);
    }
};