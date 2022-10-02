// Problem link - https://www.interviewbit.com/problems/jump-game-array/
/* Problem Solution Function 
int Solution::canJump(vector<int> &A) {
    if(A.size() <= 1) return 1;
    int counter = 1;
    int n = A.size()-2;
    while(n>=0)
    {
        if(A[n]>=counter) counter=0;
        n--;
        counter++;
    }
    if (counter == 1) return 1;
    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> A = {2,3,1,1,4};
    if(A.size() <= 1) return 1;
    int counter = 1;
    int n = A.size()-2;
    while(n>=0)
    {
        if(A[n]>=counter) counter=0;
        n--;
        counter++;
    }
    if (counter == 1) return 1;
    return 0;
}