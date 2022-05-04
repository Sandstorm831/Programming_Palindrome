//Problem link - https://www.interviewbit.com/courses/programming/topics/bit-manipulation/problems/single-number/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> A = {2,4, 4 ,5,6,5,6}; // This has to be assumed
    int n = A.size();
    int k=0;
    for(int i = 0; i<n; i++){
        k ^= A[i];
    }
    cout<<k;
}