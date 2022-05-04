// Problem Link - https://www.interviewbit.com/problems/min-xor-value/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> A = {1,4,2,4,3,2,1,1,2,4}; // This has to be assumed
    sort(A.begin(), A.end());
    long int b = numeric_limits<int>::max();
    long int n = A.size();
    for(int i=0; i<n-1; i++){
        
        int c = A[i]^A[i+1];
        if(c<b){
            b =c;
        }
        else{
            continue;
        }
    }
    cout<<b;
}