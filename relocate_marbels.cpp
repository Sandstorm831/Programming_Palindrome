// Question Link - https://leetcode.com/contest/biweekly-contest-108/problems/relocate-marbles/
// Solution 


class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> ans;
        unordered_set<int> st;
        for(int i=0; i<nums.size(); i++) st.insert(nums[i]);
        for(int i=0; i<moveFrom.size(); i++)
        {
            if(st.find(moveFrom[i]) != st.end())
            {
                st.erase(moveFrom[i]);
                st.insert(moveTo[i]);
            }
        }
        vector<int> fin;
        for(auto itr=st.begin(); itr!=st.end(); itr++) fin.push_back(*itr);
        sort(fin.begin(), fin.end());
        return fin;
    }
};