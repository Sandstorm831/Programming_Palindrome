// question Link - https://leetcode.com/problems/knight-dialer/description/
// Solution 

unordered_map<int, vector<int>> ump;
vector<vector<int>> dp(10, vector<int> (5001, -1));
int mod = 1e9+7;
class Solution {
public:
    int recursor(int num, int len)
    {
        if(len == 1) return 1;
        else if(dp[num][len] != -1) return dp[num][len];
        else
        {   
            int counter=0;
            for(int i=0; i<ump[num].size();i++) counter = (counter%mod + recursor(ump[num][i],len-1)%mod)%mod;
            return dp[num][len] = counter;
        }
    }
    int knightDialer(int n) {
        ump.clear();
        ump[0].push_back(4);
        ump[0].push_back(6);
        ump[1].push_back(6);
        ump[1].push_back(8);
        ump[2].push_back(7);
        ump[2].push_back(9);
        ump[3].push_back(8);
        ump[3].push_back(4);
        ump[4].push_back(0);
        ump[4].push_back(3);
        ump[4].push_back(9);
        ump[6].push_back(0);
        ump[6].push_back(1);
        ump[6].push_back(7);
        ump[7].push_back(2);
        ump[7].push_back(6);
        ump[8].push_back(1);
        ump[8].push_back(3);
        ump[9].push_back(2);
        ump[9].push_back(4);
        int counter=0;
        for(int i=0; i<=9; i++) counter = (counter%mod + recursor(i,n)%mod)%mod;
        return counter;        
    }
};