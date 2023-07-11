// Question Link- https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description?envType=study-plan-v2&envId=top-interview-150
// solution 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;
        int counter=0;
        for(int i=0, j=0; j<nums.size(); j++)
        {
            if(mp.find(nums[j])==mp.end())
            {
                counter++;
                mp[nums[j]] = 1;
                nums[i] = nums[j];
                i++;
            }
            else if(mp[nums[j]] == 1)
            {
                counter++;
                mp[nums[j]]++;
                nums[i] = nums[j];
                i++;
            }
        }
        return counter;
    }
};