// Question Link -https://leetcode.com/problems/predict-the-winner/description/
// Solution 

class Solution {
public:
    int recursor(vector<int>& nums, int st, int en)
    {
        if(st>en) return 0;
        return max(min(nums[st]+recursor(nums, st+2,en), nums[st]+recursor(nums, st+1, en-1)), min(nums[en]+recursor(nums, st+1, en-1), nums[en]+recursor(nums, st, en-2)));
    }
    bool PredictTheWinner(vector<int>& nums) {
        int x = recursor(nums, 0, nums.size()-1);
        int summ = accumulate(nums.begin(), nums.end(), 0);
        cout<<summ<<" "<<x<<endl;
        return 2*x>=summ;
    }
};