// Question Link - https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/?envType=study-plan-v2&envId=dynamic-programming
// solution 

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int counter = 1;
        for(int i=0;i<arr.size(); i++) 
        {
            if(dp.find(arr[i]-difference) != dp.end())dp[arr[i]]=1+dp[arr[i]-difference];
            else dp[arr[i]]=1;
            counter=max(dp[arr[i]], counter);
        }
        return counter;
    }
};