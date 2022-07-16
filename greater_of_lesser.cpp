// Problem Link - https://www.interviewbit.com/problems/greater-of-lesser/
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &A, vector<int> &B, int C) {
    int maxy = 0, miny = 0;
    for(int i= 0; i<A.size(); i++) if(A[i]>C) maxy++;
    for(int i= 0; i<B.size(); i++) if(B[i]<C) miny++;
    return max(maxy, miny);
}