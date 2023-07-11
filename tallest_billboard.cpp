// Question Link - https://leetcode.com/problems/tallest-billboard/description/
// Solution 

class Solution {
public:
    vector<vector<int>>dp;
    int recursor(vector<int>& rods, int index, int first, int second, int summ)
    {
        if(first >= summ || second >= summ) return -1;
        else if(index >= rods.size()) return first==second?first:-1;
        else if(dp[index][abs(first-second)] != -2)
        {
            if(dp[index][abs(second-first)]==-1) return -1;
            else return dp[index][abs(second-first)]+max(first,second);
        }
        else
        {
            dp[index][abs(second-first)] = max(-1,max(max(recursor(rods, index+1, first, second+rods[index], summ), recursor(rods, index+1,first+rods[index], second, summ)), recursor(rods, index+1, first,second,summ))-max(first,second));
            if(dp[index][abs(second-first)]==-1) return -1;
            else return dp[index][abs(second-first)]+max(first,second);
        }
    }
    int tallestBillboard(vector<int>& rods) {
        int summ=0;
        for(int i=0;i<rods.size();i++) summ+=rods[i];
        summ = (summ)/2;
        summ++;
        dp.clear();
        dp.resize(rods.size()+1, vector<int> (summ,-2));
        return recursor(rods, 0,0,0,summ);
    }
};