// Question LInk - https://leetcode.com/problems/merge-sorted-array/description?envType=study-plan-v2&envId=top-interview-150
// Solution 

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<nums2.size(); i++)
        {
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};