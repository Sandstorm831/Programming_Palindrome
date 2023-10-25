// Question Link - https://leetcode.com/problems/partition-array-for-maximum-sum/description/
// Solution 

class Solution {
public:
    vector<int> dp;
    int recursor(vector<int>& arr, int k, int index)
    {
        if(index  >= arr.size()) return 0;
        if(dp[index] != -1) return dp[index];
        else
        {
            int counter=INT_MIN;
            for(int i=1; i<=k; i++)
            {
                if(index+i-1 < arr.size())
                {
                    int maxer = INT_MIN;
                    for(int j=index; j<=index+i-1; j++) maxer = max(maxer, arr[j]);
                    counter = max(counter, maxer*i+recursor(arr, k, i+index));
                }
                else continue;
            }
            return dp[index] = counter;
        }
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.clear();dp.resize(arr.size()+1, -1);
        return recursor(arr, k, 0);
    }
};