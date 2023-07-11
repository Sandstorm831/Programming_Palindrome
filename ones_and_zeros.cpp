// Question LInk - https://leetcode.com/problems/ones-and-zeroes/description/
// solution 

class Solution {
public:
    vector<vector<vector<int>>> dp;
    int recursor(vector<pair<int,int>>& mod, int index, int m, int n)
    {
        // string s = to_string(m)+"|"+to_string(n); //to_string(index)+"|"+
        if(m<0 || n<0) return 0;
        if(index >= mod.size()) return 0;
        else if(dp[index][m][n] != -1) return dp[index][m][n];
        if(mod[index].first<=m && mod[index].second<=n) 
        {
            return dp[index][m][n] = max(1+recursor(mod, index+1, m-mod[index].first, n-mod[index].second) ,recursor(mod, index+1, m, n));
        }
        else return dp[index][m][n] = recursor(mod, index+1, m, n);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> mod;
        for(int i=0;i<strs.size(); i++)
        {
            int ones=0,zeros=0;
            for(int j=0; j<strs[i].size(); j++)
            {
                if(strs[i][j]=='0') zeros++;
                else ones++;
            }
            mod.push_back(make_pair(zeros,ones));
        }
        dp.clear();
        dp.resize(mod.size()+1, vector<vector<int>> (m+1, vector<int> (n+1, -1)));
        return recursor(mod, 0, m, n);
    }
};