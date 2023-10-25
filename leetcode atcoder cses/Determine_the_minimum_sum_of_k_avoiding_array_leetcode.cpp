// Question Link - https://leetcode.com/contest/weekly-contest-359/problems/determine-the-minimum-sum-of-a-k-avoiding-array/
// solution 

class Solution {
public:
    int minimumSum(int n, int k) {
        int counter=0;
        int summ =0;
        int index = 1;
        while(counter < n && index*2 <= k)
        {
            counter++;
            summ+=index;
            index++;
        }
        if(counter >= n) return summ;
        index = k;
        while(counter<n)
        {
            counter++;
            summ+=index;
            index++;
        }
        return summ;
    }
};