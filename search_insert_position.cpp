// Question Link - https://leetcode.com/problems/search-insert-position/description/?envType=study-plan-v2&envId=top-interview-150
// Solution
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target)-nums.begin();
    }
};