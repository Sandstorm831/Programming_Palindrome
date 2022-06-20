// Problem Link - https://www.interviewbit.com/problems/rearrange-array/
#include <bits/stdc++.h>
using namespace std;
void rearrange(vector<int>& A)
{
    int size = A.size();
    for(int i = 0; i<size; i++)
    {
        A[i] = (A[A[i]%size]%size)*size + A[i]%size;
    }
    for(int i=0; i<size; i++)
    {
        A[i] = (A[i] - (A[i]%size))/size;
    }
}
int main()
{}