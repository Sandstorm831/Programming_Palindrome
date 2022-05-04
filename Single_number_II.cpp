// Problem Link - https://www.interviewbit.com/courses/programming/topics/bit-manipulation/problems/single-number-ii/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> A = {1,4,2,4,3,2,1,1,2,4}; // This has to be assumed
    int n = A.size();
    int INT_SIZE = 8 * sizeof(int);
    int count[INT_SIZE];
    memset(count, 0, sizeof(count));

    for(int i=0; i<INT_SIZE; i++){
        for(int j=0; j<n; j++){
            if((A[j]&(1<<i)) != 0){
                count[i] += 1;
            }
        }
    }
    unsigned res=0;
    for(int k=0; k<INT_SIZE; k++){
        res += (count[k]%3)*(1<<k);
    }
    cout<<res;
}