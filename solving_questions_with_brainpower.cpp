// Question Link - https://leetcode.com/problems/solving-questions-with-brainpower/description?envType=study-plan-v2&envId=dynamic-programming
// Solution

class Solution {
public:
    vector<long long> dp;
    long long recursor(vector<vector<int>>& questions, long long index)
    {
        if(index>=questions.size()) return 0;
        else if(dp[index] != -1) return dp[index];
        else return dp[index] = max(questions[index][0]+recursor(questions, index+1+questions[index][1]), recursor(questions, index+1));
    }
    long long mostPoints(vector<vector<int>>& questions) {
        dp.clear();dp.resize(questions.size()+1, -1);
        return recursor(questions, 0);
    }
};