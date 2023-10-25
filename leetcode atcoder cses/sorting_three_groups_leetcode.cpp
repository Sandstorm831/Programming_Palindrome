// Question link - https://leetcode.com/problems/sorting-three-groups/description/
// solution 

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> dp(4, nums.size());
        for(int i=0; i<nums.size(); i++)
        {
            dp[nums[i]]--;
            dp[2] = min(dp[2], dp[1]);
            dp[3] = min(dp[3], dp[2]);
        }
        return dp[3];
    }
};
// for explanation  - https://leetcode.com/problems/sorting-three-groups/solutions/3932395/java-c-python-dp-6-lines-o-n/

// Another solution 

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        int counter=0;
        temp.push_back(nums[0]);
        for(int i=1; i<n; i++)
        {
            auto l = lower_bound(temp.begin(), temp.end(), nums[i]);
            auto o = upper_bound(temp.begin(), temp.end(), nums[i]);
            if(o == temp.end()) temp.push_back(nums[i]);
            else
            {
                int index = o-temp.begin();
                temp[index] = nums[i];
                counter++;
            }
        }
        return counter;
    }
};