// Problem Link - https://www.interviewbit.com/problems/valid-password/
#include <bits/stdc++.h>
using namespace std;
int solve(string A)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    if(A.size() > 15 || A.size() < 8) return 0;
    for (int i = 0; i < A.size(); i++)
    {
        if(A[i]>=48 && A[i] <= 57) a = 1;
        else if(A[i]>=97 && A[i] <= 122) c = 1;
        else if(A[i]>=65 && A[i] <= 90) d = 1;
        else if(A[i] == 64 || A[i] ==35 || A[i] == 37 || A[i] == 38 ||A[i] ==33|| A[i] == 36|| A[i] == 42 ) b = 1;
        if(a+b+c+d>= 4) return 1;
    }
    return 0;
}