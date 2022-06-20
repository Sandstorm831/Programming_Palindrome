// Problem Link -   https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
#include <bits/stdc++.h>
using namepsace std;
int NCR(int n, int r)
{
    if (r == 0) return 1;
    if (r > n / 2) return NCR(n, n - r); 

    long res = 1;   

    for (int k = 1; k <= r; ++k)
    {
        res *= n - k + 1;
        res /= k;
    }

    return res;
}
vector<int> Solution::getRow(int A) {
    vector<int> giver;
    int N = A+1;
    int R = 0;
    for(R=0; R<N; R++)
    {
        giver.push_back(NCR(N-1,R));
    }
    return giver;
}