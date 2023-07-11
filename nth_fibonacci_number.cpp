// Question Link - https://leetcode.com/problems/n-th-tribonacci-number/description?envType=study-plan-v2&envId=dynamic-programming
// Solution 

class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        else if(n<3) return 1;
        vector<int> t(n+1, 0);
        t[0] = 0, t[1]=1, t[2]=1;
        for(int i=3; i<=n; i++) t[i] = t[i-1]+t[i-2]+t[i-3];
        return t[n];
    }
};