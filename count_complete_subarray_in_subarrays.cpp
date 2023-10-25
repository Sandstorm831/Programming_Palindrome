// Question Link - https://leetcode.com/contest/weekly-contest-356/problems/count-complete-subarrays-in-an-array/
// Solution 

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> ump, curr;
        for(int i=0; i<nums.size(); i++)
        {
            if(ump.find(nums[i]) == ump.end()) ump[nums[i]] = 1;
            else ump[nums[i]]++;
        }
        int x = ump.size();
        int counter=0;
        for(int i=0;i<nums.size();i++)
        {
            curr.clear();
            for(int j=i; j<nums.size(); j++)
            {
                if(curr.find(nums[j]) == curr.end()) curr[nums[j]]=1;
                else curr[nums[j]]++;
                if(curr.size() == x) counter++;
            }
        }
        return counter;
    }
};