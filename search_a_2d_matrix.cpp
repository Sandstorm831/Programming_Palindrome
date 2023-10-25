// Question Link - https://leetcode.com/problems/search-a-2d-matrix/description?envType=study-plan-v2&envId=top-interview-150
// Solution 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++)
        {
            if(lower_bound(matrix[i].begin(), matrix[i].end(), target)-matrix[i].begin() < matrix[i].size())
            {
                if(matrix[i][lower_bound(matrix[i].begin(), matrix[i].end(), target)-matrix[i].begin()] != target) return false;
                else return true;
            }
        }
    return false;
    }
};