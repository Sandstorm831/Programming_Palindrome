// Question link - https://leetcode.com/contest/biweekly-contest-110/problems/minimum-seconds-to-equalize-a-circular-array/
// solution

class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int,vector<int>> ump;
        for(int i=0;i<nums.size(); i++)
        {
            ump[nums[i]].push_back(i);
        }
        int minn = INT_MAX;
        for(auto itr=ump.begin(); itr!=ump.end(); itr++)
        {
            int s;
            if(((itr->second).back() + 1)%(nums.size()) == (itr->second)[0]) s = 0;
            else s = (nums.size()-(itr->second).back()-1 + (itr->second)[0]+1)/2;
            int maxer = INT_MIN;
            for(int i=0; i<(itr->second).size()-1;i++)
            {
                if((itr->second)[i+1]-(itr->second)[i] == 1) maxer = max(maxer, 0);
                else maxer = max(maxer, ((itr->second)[i+1]-(itr->second)[i])/2);
            }
            maxer = max(maxer, s);
            minn = min(minn, maxer);
        }
        return max(minn,0);
    }
};