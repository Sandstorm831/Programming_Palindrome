// Question Link - https://leetcode.com/problems/find-the-highest-altitude/description/
// Solution 

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxx = 0;
        int curr = 0;
        for(int i=0; i<gain.size(); i++) 
        {
            curr += gain[i];
            maxx = max(maxx, curr);
        }
        return maxx;
    }
};