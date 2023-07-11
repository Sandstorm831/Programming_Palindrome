// Question LInk - https://leetcode.com/problems/make-array-strictly-increasing/description
// Solution 

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        unordered_map<int,int> dp;
        dp[-1] = 0;
        for(int i=0;i<arr1.size();i++)
        {
            unordered_map<int,int> new_dp;
            for(auto itr = dp.begin(); itr != dp.end(); itr++)
            {
                if(arr1[i] > itr->first)
                {
                    if(new_dp.find(arr1[i]) == new_dp.end()) new_dp[arr1[i]] = itr->second ;
                    else new_dp[arr1[i]] = min(new_dp[arr1[i]], itr->second);
                }
                int index = upper_bound(arr2.begin(), arr2.end(),itr->first)-arr2.begin();
                if(index < arr2.size())
                {
                    if(new_dp.find(arr2[index]) == new_dp.end()) new_dp[arr2[index]] = 1+itr->second;
                    else new_dp[arr2[index]] = min(new_dp[arr2[index]], 1+itr->second);
                }
            }
            dp = new_dp;
        }
        int maxx = INT_MAX;
        for(auto itr = dp.begin(); itr != dp.end(); itr++) maxx = min(maxx, itr->second);
        return maxx==INT_MAX ? -1:maxx;
    }
};