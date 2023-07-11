// Question LInk - https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/description/
// Solution 

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> dp;
        for(int i=0; i<obstacles.size(); i++)
        {
            int x = obstacles[i];
            if(dp.empty() || dp.back()<=x)
            {
                dp.push_back(x);
                obstacles[i] = dp.size();
            }
            else 
            {
                int l = upper_bound(dp.begin(), dp.end(), obstacles[i])-dp.begin();
                dp[l]=x;
                obstacles[i] = l+1;
            }
        }
        return obstacles;
    }
};