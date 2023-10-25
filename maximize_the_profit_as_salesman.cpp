// Question Link - https://leetcode.com/contest/weekly-contest-359/problems/maximize-the-profit-as-the-salesman/
// solution

class Solution {
public:
    vector<int> dp;
    vector<int> lob;
    int recursor(int n, vector<vector<int>>& offers, int index)
    {
        if(index>=offers.size()) return 0;
        else if(dp[index] != -1) return dp[index];
        else
        {
            int ind = upper_bound(lob.begin(),lob.end(), offers[index][1])-lob.begin();
            int x = max(offers[index][2]+recursor(n, offers, ind), recursor(n, offers, index+1));
            return dp[index] = x;
        }
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        dp.resize(offers.size()+1, -1);
        sort(offers.begin(), offers.end());
        lob.clear();
        for(int i=0; i<offers.size(); i++)
        {
            lob.push_back(offers[i][0]);
        }
        return recursor(n, offers, 0);
    }
};