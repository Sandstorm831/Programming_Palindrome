// Problem Link - https://www.interviewbit.com/problems/all-factors/
#include <bits/stdc++.h>
using namespace std;
vector<int> allFactors(int A)
{
    vector<int> factors;
    int i;
    for(i=1; i*i <= A; i++)
    {
        if(A%i == 0) factors.push_back(i);
    }
    int size = factors.size();
    for(int j = size-1; j>=0; j--)
    {
        if(factors[j]*factors[j] == A) continue;
        factors.push_back(A/factors[j]);
    }
    return factors;
}