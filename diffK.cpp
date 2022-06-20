// Problem Link - https://www.interviewbit.com/problems/diffk/
/* Problem Solution Function ---------------------------------+
int Solution::diffPossible(vector<int> &A, int B) {     <-----+
    int j = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (; j < A.size(); j++)
        {
            if(A[j]- A[i] == B && i!=j) return 1;
            if(A[j]-A[i] > B) break;
        }
        
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int diffPosible(vector<int>&A, int B)
{
    int j = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (; j < A.size(); j++)
        {
            if(A[j]- A[i] == B && i!=j) return 1;
            if(A[j]-A[i] > B) break;
        }
        
    }
    return 0;
    
}