// question link - https://leetcode.com/problems/find-the-town-judge/description?envType=study-plan-v2&envId=graph-theory
// solution 

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> v(n+1, vector<int> ());
        for(int i=0; i<trust.size();i++)
        {
            v[trust[i][0]].push_back(trust[i][1]);
        }
        int spec=-1;
        for(int j=1;j<v.size(); j++)
        {
            if(v[j].empty())
            {
                spec=j;
                break;
            }
        }
        if(spec==-1)return -1;
        else
        {
            for(int j=1; j<v.size();j++)
            {
                if(j==spec) continue;
                bool find = false;
                for(int k=0; k<v[j].size();k++)
                {
                    if(v[j][k]==spec) find=true;
                }
                if(!find) return -1;
            }
        }
        return spec;
    }
};