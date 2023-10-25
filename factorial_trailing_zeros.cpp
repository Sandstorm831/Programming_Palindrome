// Question Link - https://leetcode.com/problems/factorial-trailing-zeroes/description/?envType=study-plan-v2&envId=top-interview-150
// solution 

class Solution {
public:
    int trailingZeroes(int n) {
        int p = 1;
        int counter=0;
        while(n / pow(5,p) >= 1) 
        {
            counter += n / pow(5,p);
            p++;
        }
        return counter;
    }
};