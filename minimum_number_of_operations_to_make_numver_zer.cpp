// Question LInk - https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/description/
// Solution 

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long a = num1*1ll, b = num2*1ll;
        if(a<b) return -1;
        for(int i=1; i<61; i++)
        {
            if(a-i*b >= 0 && __builtin_popcountll(a-i*b)<=i && a-i*b >= i) return i;
        }
        return -1;
    }
};