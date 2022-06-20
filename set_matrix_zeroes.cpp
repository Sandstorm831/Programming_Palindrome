// Problem Link - https://www.interviewbit.com/problems/set-matrix-zeros/
#include <bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>> A)
{
    unordered_set<int> xpos;
    unordered_set<int> ypos;
    for (int y = 0; y < A.size(); y++)
    {
        for (int x = 0; x < A[0].size(); x++)
        {
            if(A[y][x] == 0)
            {
                xpos.insert(x);
                ypos.insert(y);
            }
        }
        
    }
    for (int y = 0; y < A.size(); y++)
    {
        for (int x = 0; x < A[0].size(); x++)
        {
            if(xpos.find(x) != xpos.end() || ypos.find(y) != ypos.end())
            {
                A[y][x] = 0;
            }
        }
        
    }
}