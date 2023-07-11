// Question LInk - https://leetcode.com/problems/russian-doll-envelopes/description/
// Solution 

bool comp(vector<int>& a, vector<int>& b)
{
    if(a[0] < b[0]) return true;
    else if(a[0] == b[0] && a[1] > b[1]) return true;
    return false;
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); 
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> sec;
        for(int i=0; i<envelopes.size(); i++) sec.push_back(envelopes[i][1]);
        vector<int> dp;
        dp.push_back(sec[0]);
        for(int i=1; i<sec.size(); i++)
        {
            int l = lower_bound(dp.begin(), dp.end(), sec[i])-dp.begin();
            if(l >= dp.size()) dp.push_back(sec[i]);
            else dp[l] = sec[i];
        }
        return dp.size();
    }
};