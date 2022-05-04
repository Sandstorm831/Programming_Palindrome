// Problem link - https://www.interviewbit.com/problems/is-rectangle/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int A=33, B=32, C=33, D=32; //These values are to be assumed
    set<int> s;
    int summer=0;
    int sum = A+B+C+D;
    s.insert(A);
    s.insert(B);
    s.insert(C);
    s.insert(D);
    set<int>::iterator itr;
    for (itr = s.begin(); itr != s.end(); itr++) {
        summer += *itr;
    }
    if(s.size() == 2){
        if(2*summer == sum){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<0;
    }
}