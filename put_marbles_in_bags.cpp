// Question Link - https://leetcode.com/problems/put-marbles-in-bags/description
// Solution 

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> pairs;
        for(long long i=0; i<weights.size()-1;i++) pairs.push_back(1ll*weights[i]+1ll*weights[i+1]);
        sort(pairs.begin(), pairs.end());
        long long n=pairs.size();
        long long ans=0;
        for(long long i=0; i<k-1; i++) ans+=pairs[n-1-i]-pairs[i];
        return ans;
    }
};