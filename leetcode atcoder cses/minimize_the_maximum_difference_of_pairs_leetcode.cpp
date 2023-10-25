// Question LInk - https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/
// solution 

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size(); int left = 0; int right = nums.back()-nums[0];
        while(left < right)
        {
            int mid = (left + right + 1)/2, pairs=0;
            for(int i=1; i<n && pairs<p; i++)
            {
                if(nums[i]-nums[i-1] < mid) pairs++,i++;
            }
            if(pairs<p) left = mid;
            else right = mid-1;
        }
        return left;
    }
};

// For Explanation - https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/solutions/3395750/java-c-python-binary-search/