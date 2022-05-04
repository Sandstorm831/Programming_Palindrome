// Problem Link - https://www.interviewbit.com/problems/greatest-common-divisor/
#include <bits/stdc++.h>
using namespace std;

int gcd(int A, int B){
    if(B==0){

        return A;
    }
    return gcd(B, A%B);
}

int main()
{
    int A = 432, B =234;
    cout<<gcd(A, B);
}