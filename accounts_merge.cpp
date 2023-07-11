// QUestion LInk - https://leetcode.com/problems/accounts-merge/description/?envType=study-plan-v2&envId=graph-theory
// Solution 

class Solution {
public:
    int finder(int node, vector<pair<string,int>>& elder)
    {
        if(elder[node].second == node) return elder[node].second;
        else elder[node].second = finder(elder[node].second, elder);
        return elder[node].second;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<pair<string,int>> elder;
        for(int i=0;i<accounts.size();i++)
        {
            elder.push_back(make_pair(accounts[i][0], i));
        }
        unordered_map<string,int> mp;
        vector<set<string>> vs(accounts.size(), set<string>());
        for(int i=0; i<accounts.size(); i++)
        {
            int found=-1;
            for(int j=1;j<accounts[i].size();j++)
            {
                if(mp.find(accounts[i][j]) == mp.end())
                {
                    elder.push_back(make_pair(accounts[i][j],i));
                    mp[accounts[i][j]] = elder.size()-1;
                }
                else
                {
                    int grp = finder(mp[accounts[i][j]], elder);
                    int orig = finder(i,elder);
                    elder[orig].second = grp;
                }
            }
        }
        vector<vector<string>> ans;
        for(int i=accounts.size(); i<elder.size(); i++)
        {
            int grp = finder(elder[i].second, elder);
            vs[grp].insert(elder[i].first);
        }
        for(int i=0; i<vs.size(); i++)
        {
            vector<string> ss;
            if(!vs[i].empty())
            {
                ss.push_back(accounts[i][0]);
                for(auto j=vs[i].begin();j!=vs[i].end(); j++)
                {
                    ss.push_back(*j);
                }
            }
            if(!ss.empty())
            {
                ans.push_back(ss);
            }
        }
        return ans;
    }
};