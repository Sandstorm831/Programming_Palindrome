// question Link - https://leetcode.com/contest/weekly-contest-356/problems/number-of-employees-who-met-the-target/
// solution 

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int counter=0;
        for(int i=0;i<hours.size();i++)if(hours[i]>=target)counter++;
        return counter;
    }
};