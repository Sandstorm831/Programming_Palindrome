// Problem Link - https://www.interviewbit.com/problems/armstrong-number/
#include <bits/stdc++.h>
using namespace std;
int solve(int A) {
    int a = A;
    int sum = 0;
    int n = 0;
    while(a > 0)
    {
        a = a/10;
        n++;
    }
    a = A;
    while(a>0)
    {
        sum += pow(a%10, n);
        a  = a/10;
    }
    if(sum == A) return 1;
    return 0;
}