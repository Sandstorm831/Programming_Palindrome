// Question link - https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/description/
// solution 

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        vector<int> v((1<<16)+1, 0);
        for(int i=0; i<nums.size(); i++)for(int j=0;j<nums.size(); j++) v[nums[i]&nums[j]]++;
        int counter=0;
        for(int i=0; i<nums.size();i++) for(int j=0; j<=(1<<16); j++) if((j&nums[i]) == 0) counter+=v[j];
        return counter;
    }
};