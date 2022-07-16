// Problem Link - https://www.interviewbit.com/problems/leap-year/
#include <bits/stdc++.h>
using namespace std;
int solve(int A) {
    if(A%400 == 0 ) return 1;
    else if( A%4 == 0 && A%100 != 0) return 1;
    else return 0;
}