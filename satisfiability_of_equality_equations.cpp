// Questoin Link - https://leetcode.com/problems/satisfiability-of-equality-equations/description/?envType=study-plan-v2&envId=graph-theory
class Solution {
public:
    int finder(int node, vector<pair<char,int>>& elder)
    {
        if(node == elder[node].second) return node;
        else elder[node].second = finder(elder[node].second, elder);
        return elder[node].second;
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int> index;
        vector<pair<char,int>> elder;
        unordered_map<char,int> mp;
        for(int i=0; i<equations.size(); i++)
        {
            if(equations[i][1] == '!') 
            {
                cout<<equations[i][0]<<" {} "<<equations[i][3]<<endl;
                index.push_back(i);
                continue;
            }
            if(mp.find(equations[i][0]) == mp.end() && mp.find(equations[i][3]) == mp.end())
            {
                cout<<equations[i][0]<<" | "<<equations[i][3]<<endl;
                int x = elder.size();
                elder.push_back(make_pair(equations[i][0],x));
                elder.push_back(make_pair(equations[i][3],x));
                mp[equations[i][0]] = x;
                mp[equations[i][3]] = x+1;
            }
            else if(mp.find(equations[i][0]) != mp.end() && mp.find(equations[i][3]) == mp.end())
            {
                int x = finder(mp[equations[i][0]],elder);
                elder.push_back(make_pair(equations[i][3],x));
                mp[equations[i][3]] = elder.size()-1;
            }
            else if(mp.find(equations[i][0]) == mp.end() && mp.find(equations[i][3]) != mp.end())
            {
                int x = finder(mp[equations[i][3]], elder);
                elder.push_back(make_pair(equations[i][0],x));
                mp[equations[i][0]] = elder.size()-1;
            }
            else
            {
                int x = finder(mp[equations[i][3]], elder);
                int y = finder(mp[equations[i][0]], elder);
                if(x != y) elder[y].second = x;
            }
        }
        for(int i=0; i<index.size(); i++)
        {
            if(equations[index[i]][0] == equations[index[i]][3]) return false;
            if(mp.find(equations[index[i]][0]) != mp.end() && mp.find(equations[index[i]][3]) != mp.end())
            {
                cout<<equations[index[i]][0]<<" <> "<<equations[index[i]][3]<<endl;
                if(finder(mp[equations[index[i]][0]],elder) == finder(mp[equations[index[i]][3]], elder)) return false;
            }
        }
        return true;
    }
};