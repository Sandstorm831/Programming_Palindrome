//Problem Link - https://www.interviewbit.com/problems/grid-unique-paths/
#include <bits/stdc++.h>
using namespace std;
int uniquePahts(int A, int B)
{
    if(A==1 || B==1) return 1;
    int num1 = uniquePahts(A-1, B);
    int num2 = uniquePahts(A,B-1);
    return num1+num2;
}
int main()
{
    cout<<uniquePahts(5);
}