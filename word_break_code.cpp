// Question Link - https://leetcode.com/problems/word-break/description?envType=study-plan-v2&envId=dynamic-programming
// Solution 

class Solution {
public:
    vector<vector<int>> dp;
    bool recursor(string& s, unordered_set<string>& dump, string make, int index)
    {
        if(index >= s.size() && !make.empty()) return false;
        else if(index >= s.size() && make.empty()) return true;
        else if(dp[make.size()][index] != -1) return dp[make.size()][index];
        make += s[index];
        if(dump.find(make) != dump.end())
        {
            bool a = recursor(s, dump, make, index+1);
            string t = make;
            make.clear();
            bool b = recursor(s, dump, make, index+1);
            make = t;
            return dp[make.size()][index] = (a|b);
        } 
        else
        {
            return recursor(s, dump, make, index+1);
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        string make="";
        unordered_set<string> dump;
        for(int i=0; i<wordDict.size(); i++)
        {
            dump.insert(wordDict[i]);
        }
        dp.clear(); dp.resize(s.size()+1, vector<int> (s.size()+1, -1));
        return recursor(s, dump, make,0);
    }
};
