// Question Link - https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=study-plan-v2&envId=top-interview-150
// Solution 

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        return left!=right?(rangeBitwiseAnd(left>>1, right>>1))<<1:left;
    }
};
/*

Explanation - https://leetcode.com/problems/bitwise-and-of-numbers-range/solutions/56729/bit-operation-solution-java/?envType=study-plan-v2&envId=top-interview-150

*/