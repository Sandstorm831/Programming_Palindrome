// Question Link - https://leetcode.com/problems/max-points-on-a-line/description/?envType=study-plan-v2&envId=top-interview-150
// Solution 

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 1) return 1;
        unordered_map<double, int> ump;
        int maxy = INT_MIN;
        for(int i=0; i<points.size(); i++)
        {
            ump.clear();
            int maxx = INT_MIN;
            for(int j = i+1; j<points.size(); j++)
            {
                if(points[i][1] != points[j][1])
                {
                    double slop = double(points[i][0] - points[j][0]) / double(points[i][1] - points[j][1]);
                    if(ump.find(slop) == ump.end()) {ump[slop] = 2; maxx = max(maxx, ump[slop]);}
                    else
                    {
                        ump[slop]++; maxx = max(maxx, ump[slop]);
                    }
                }
                else 
                {
                    if(ump.find(INT_MAX) == ump.end()) ump[INT_MAX] = 2;
                    else ump[INT_MAX]++;
                    maxx = max(maxx, ump[INT_MAX]);
                }
            }
            maxy = max(maxx, maxy);
        }
        return maxy;
    }
};