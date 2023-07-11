// Question Link - https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/description/
// Solution 

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int maxx = INT_MIN;
        int length=0;
        int curr = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]%2 == curr && nums[i]<=threshold)
            {
                // cout<<nums[i]<<" "<<curr<<" | ";
                curr = (curr+1)%2;
                length++;
                maxx = max(maxx, length);
            }
            else
            {
                curr = 0;
                length=0;
                if(nums[i]%2 == curr && nums[i]<=threshold)
                {
                    // cout<<nums[i]<<" "<<curr<<" | ";
                    curr = (curr+1)%2;
                    length++;
                    maxx = max(maxx, length);
                }
            }
        }
        // cout<<endl;
        return max(maxx,0);
    }
};