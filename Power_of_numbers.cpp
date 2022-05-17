// Problem Link - https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1/?page=1&category[]=Recursion&sortBy=submissions
#include <bits/stdc++.h>
using namespace std;
int main(){
    int N = 90, R = 9; // have to be assumed
    long long int res =1;
    while(R>0){
        cout<<"entered while"<<endl;
        if((R&1) != 0){
            res = (res*N);
            cout<<"entered if "<<endl;
        }
         R = R/2;
         N = (N * N);
    }
    cout<<res;
       
        
}
