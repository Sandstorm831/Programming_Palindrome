// Question Link - https://leetcode.com/problems/total-distance-traveled/description/
// Solution 

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans=0;
        while(mainTank >= 5 && additionalTank > 0)
        {
            mainTank += 1-5;
            additionalTank -=1;
            ans += 50;
        }
        if(additionalTank == 0)
        {
            ans += 10*mainTank;
        }
        else if(mainTank<5 && additionalTank>0)
        {
            ans += mainTank*10;
        }
        return ans;
    }
};