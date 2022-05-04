// Question Link - https://www.interviewbit.com/problems/total-moves-for-bishop/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A=5, B=4; // This is to be assumed
    int C=0; int D=9-A;
    if(A<=B){
        C += A-1+8-B;
    }
    else if(A>B){
        C += B-1+8-A;
    }
    if(D<=B){
        C += D-1+8-B;
    }
    else if(D>B){
        C += B-1+8-D;
    }
    cout<<C;
}