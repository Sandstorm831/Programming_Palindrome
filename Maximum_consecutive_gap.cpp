//  Problem Link - https://www.interviewbit.com/problems/maximum-consecutive-gap/
#include <bits/stdc++.h>
using namespace std;
int maximumgap(vector<int>& A)
{
    int maxy = A[0]; int miny = A[0];
    for (int i = 0; i < A.size(); i++)
    {
        maxy = max(maxy, A[i]);
        miny = min(miny, A[i]);
    }
    int size = A.size();
    vector<int> max_bucket(size-1, INT_MIN); vector<int> min_bucket(size-1, INT_MAX);
    float Digy = (float)(maxy-miny)/(float)(size-1);
    for (int i = 0; i < A.size(); i++)
    {
        if(A[i] == maxy || A[i] == miny) continue;
        int index = (float)(floor(A[i]- miny)/Digy);
        max_bucket[index] = max(max_bucket[index], A[i]);
        min_bucket[index] = min(min_bucket[index], A[i]);
    }
    int max_gap = 0;
    int prevel = miny;
    for (int i = 0; i < min_bucket.size(); i++)
    {
        if(min_bucket[i] == INT_MAX) continue;
        max_gap = max(max_gap, min_bucket[i] - prevel);
        prevel = max_bucket[i];
    }
    max_gap = max(max_gap, maxy-prevel);
    return max_gap;
}
int main()
{}
