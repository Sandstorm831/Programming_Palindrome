//Problem Link - https://www.interviewbit.com/problems/xor-ing-the-subarrays/
#include <bits/stdc++.h>
using namespace std;
int main ()
{
    vector<int> A = {2,4, 4 ,5,6,5,6}; // This has to be assumed
    long long int a=0;
    int n = A.size();
    for(int i=0; i<n; i++){
        if(((n-2*(i))*(i+1)+(i+1)*(i))%2 != 0){
            a^=A[i];
        }
    }
    cout<<a;
}