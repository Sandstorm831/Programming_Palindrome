// Qustion Link - https://leetcode.com/problems/perfect-squares/description/?envType=study-plan-v2&envId=dynamic-programming
// Solution 

class Solution {
public:
    vector<vector<int>> dp;
    long long recursor(vector<long long>& v, long long n, long long index)
    {
        if(index<0 && n != 0) return INT_MAX;
        else if(index<0 && n==0) return 0;
        else if(n<0) return INT_MAX;
        else if(dp[index][n] != -1) return dp[index][n];
        return dp[index][n] = min(1+recursor(v,n-(v[index]*v[index]), index), recursor(v, n, index-1));
    }
    int numSquares(int n) {
        vector<long long> v;
        long long x = sqrt(n);
        for(long long i=1; i<=x; i++)v.push_back(i);
        dp.clear();dp.resize(v.size()+1, vector<int> (n+1,-1));
        return recursor(v, n, v.size()-1);
    }
};