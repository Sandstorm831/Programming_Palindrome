// Question Link - https://leetcode.com/contest/weekly-contest-351/problems/robot-collisions/
// Solution 

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        if(positions.size()==1) return healths;
        vector<pair<int,pair<int,int>>> vp;
        vector<pair<pair<int,int>,pair<int,int>>> data;
        for(int i=0; i<positions.size();i++)
        {
            if(directions[i] == 'R') data.push_back(make_pair(make_pair(positions[i],i), make_pair(healths[i],1)));
            else data.push_back(make_pair(make_pair(positions[i],i), make_pair(healths[i],-1)));
        }
        sort(data.begin(), data.end());
        vp.push_back(make_pair(data[0].first.second,make_pair(data[0].second.first, data[0].second.second)));
        for(int i=1; i<data.size();i++)
        {
            if(data[i].second.second == -1)
            {
                int x = 0;
                while(vp.size()>0 && vp.back().second.second == 1)
                {
                    if(vp.back().second.first > data[i].second.first)
                    {
                        vp.back().second.first -=1;
                        x=1;
                        break;
                    }
                    else if(vp.back().second.first < data[i].second.first) 
                    {
                        vp.pop_back();
                        data[i].second.first -= 1;
                        x=2;
                    }
                    else
                    {
                        vp.pop_back();
                        data[i].second.first = 0;
                        x=3;
                        break;
                    }
                }
                if(x==0) vp.push_back(make_pair(data[i].first.second, make_pair(data[i].second.first, data[i].second.second)));
                if(x==2) vp.push_back(make_pair(data[i].first.second, make_pair(data[i].second.first, data[i].second.second)));
            }
            else vp.push_back(make_pair(data[i].first.second,make_pair(data[i].second.first, data[i].second.second)));
        }
        vector<pair<int,int>> vv;
        for(int i=0;i<vp.size();i++)
        {
            vv.push_back(make_pair(vp[i].first, vp[i].second.first));
        }
        sort(vv.begin(), vv.end());
        vector<int> xc;
        for(int i=0; i<vv.size(); i++)
        {
            xc.push_back(vv[i].second);
        }
        return xc;
    }
};