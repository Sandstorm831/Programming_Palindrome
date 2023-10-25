// Question Link - https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
//solution 

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        map<int, int> dp = {{0, 0}};
        for (auto& job : jobs) {
            int cur = prev(dp.upper_bound(job[1]))->second + job[2];
            if (cur > dp.rbegin()->second)
                dp[job[0]] = cur;
        }
        return dp.rbegin()->second;
    }
/* 
Explanation - https://leetcode.com/problems/maximum-profit-in-job-scheduling/solutions/409009/java-c-python-dp-solution/
*/

    vector<int> dp;
    int solve(int s,int &n,int end,vector<vector<int>> &v){
        if(s>=n){
            return 0;
        }
        if(v[s][0]<end){
            return solve(s+1,n,end,v);
        }
        if(dp[s] != -1)return dp[s];
        return dp[s] = max(solve(s+1,n,end,v), v[s][2]+solve(s+1,n,v[s][1],v));
    }
    int jobsScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> v;
        int i,n = endTime.size();
        for(i = 0; i < n; i++){
            v.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(v.begin(),v.end());
        dp.clear(); dp.resize(n,-1);
        return solve(0,n,0,v);
    }
};