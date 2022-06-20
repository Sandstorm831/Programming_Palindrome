// Problem Link - https://www.interviewbit.com/problems/minimum-parantheses/
/* Problem Solution Functino --------------+
int Solution::solve(string A) {        <---+
    int open = 0; int closed = 0;
    for(int i = 0; i<A.size(); i++)
    {
        if(A[i] == ')' && open == 0) closed++;
        else if(A[i] == ')') open--;
        else open++;
    }
    return open+closed;
}
*/
#include <bits/stdc++.h>
using namespace std;
int minparenthseis(string A)
{
    int open = 0; int closed = 0;
    for(int i = 0; i<A.size(); i++)
    {
        if(A[i] == ')' && open == 0) closed++;
        else if(A[i] == ')') open--;
        else open++;
    }
    return open+closed;
}
int main()
{
    cout<<minparenthseis("))((()()()()()))))))(((()())))(()())()");
}