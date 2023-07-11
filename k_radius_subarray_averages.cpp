// Question LInk - https://leetcode.com/problems/k-radius-subarray-averages/description/
// solution 

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long n = nums.size();
        vector<int> v;
        if(n <= 2*k) 
        {
            for(long long i=0; i<n; i++) v.push_back(-1);
            return v;
        }
        else
        {
            for(long long i=0; i<k; i++) v.push_back(-1);
            long long summ = 0;
            for(long long i=0;i<2*k+1;i++) summ+= 1ll*nums[i];
            v.push_back(summ/(2*k+1));
            for(long long i = 2*k+1; i<n; i++)
            {
                summ += 1ll*nums[i]-1ll*nums[i-2*k-1];
                v.push_back(summ/(2*k+1));
            }
            for(long long i=0;i<k; i++) v.push_back(-1);
            return v;
        }

    }
};