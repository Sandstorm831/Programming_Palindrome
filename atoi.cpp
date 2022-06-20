// Problem Solving - https://www.interviewbit.com/problems/atoi/
/*Problem Solution Function
int Solution::atoi(const string A) {
    long int fine =0;
    int minus = 0;
    int i = 0;
    if(A[0] == '+') i = 1;
    else if(A[0] == '-')
    {
        i = 1;
        minus = 1;
    }
    for (i; i < A.size(); i++)
    {
        if(fine > INT_MAX && minus == 1) return INT_MIN;
        else if( fine > INT_MAX) return INT_MAX;
        int next = A[i]-48;
        if(next>=0 && next<=9) fine = fine*10 + next;
        else break;

    }
    if(minus == 0) return fine;
    else return -fine;
}
*/
#include <bits/stdc++.h>
using namepsace std;
int atoi(string A)
{
    long int fine =0;
    int minus = 0;
    int i = 0;
    if(A[0] == '+') i = 1;
    else if(A[0] == '-')
    {
        i = 1;
        minus = 1;
    }
    for (i; i < A.size(); i++)
    {
        if(fine > INT_MAX && minus == 1) return INT_MIN;
        else if( fine > INT_MAX) return INT_MAX;
        int next = A[i]-48;
        if(next>=0 && next<=9) fine = fine*10 + next;
        else break;

    }
    if(minus == 0) return fine;
    else return -fine;
}