//problem Link - https://www.interviewbit.com/problems/noble-integer/
#include <bits/stdc++.h>
using namespace std
int nobler(vector<int> A)
{
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size()-1; i++)
    {
        if(A[i] == A[i+1]) continue;
        else
        {
            if(A[i] == A.size()-i-1) return 1;
        }
        
    }
    if(A.back() == 0) return 1;
    return -1;
    
}
int main(){

}