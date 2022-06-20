// Problem Link - https://www.interviewbit.com/problems/container-with-most-water/
/* Problem Solution function ---------------------+
int Solution::maxArea(vector<int> &A) {     <-----+
    int low = 0;
    int high = A.size()-1;
    int max_area = min(A[0], A.back())*(high-low);
    while(low<high)
    {
        if(min(A[low], A[high]) == A[low]) low++;
        else high--;
        int area = min(A[low], A[high])*(high - low);
        max_area = area>max_area?area:max_area;
    }
    return max_area;
}
*/
#include <bits/stdc++.h>
using namespace std;
int maxArea(vector<int> &A)
{
    int low = 0;
    int high = A.size()-1;
    int max_area = min(A[0], A.back())*(high-low);
    while(low<high)
    {
        if(min(A[low], A[high]) == A[low]) low++;
        else high--;
        area = min(A[low], A[high])*(high - low);
        max_area = area>max_area?area:max_area;
    }
    return max_area;
}