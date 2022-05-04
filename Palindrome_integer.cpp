// Problem Link - https://www.interviewbit.com/problems/palindrome-integer/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int A = 34543; //This has to be assumed
    long int reverse =0;
    long int a = A;
    long int B = A;
    // loop to reverse integer of a normal integer
    while(a!=0){
        reverse = a%10 + reverse*10;
        a = a/10;   
    }

    if(B<0){
        cout<<0;
    }
    else if (reverse == B){
        cout<<1;
    }
    else{
        cout<<0;
    }
}