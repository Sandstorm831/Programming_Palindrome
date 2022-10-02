/*
Problem Link - https://www.interviewbit.com/problems/max-product-subarray/
int producter(vector<int> A)
{
    int a = A.size();
    if(a == 1) return A[0];
    int fprod=A[0];
    int bprod=A[a-1];
    int maxx_prod=INT_MIN;
    for(int i=1; i<a; i++)
    {
        maxx_prod = max({fprod, bprod, maxx_prod});
        bprod*=A[a-1-i];
        fprod*=A[i];
        if(fprod==0) fprod = A[i];
        if(bprod == 0) bprod = A[a-1-i];
    }
    maxx_prod = max({fprod, bprod, maxx_prod});
    return maxx_prod;
}
int Solution::maxProduct(const vector<int> &A) {
    return producter(A);
}
*/
#include <bits/stdc++.h>
using namespace std;
int producter(vector<int> A)
{
    int a = A.size();
    if(a == 1) return A[0];
    int fprod=A[0];
    int bprod=A[a-1];
    int maxx_prod=INT_MIN;
    for(int i=1; i<a; i++)
    {
        maxx_prod = max({fprod, bprod, maxx_prod});
        bprod*=A[a-1-i];
        fprod*=A[i];
        if(fprod==0) fprod = A[i];
        if(bprod == 0) bprod = A[a-1-i];
    }
    maxx_prod = max({fprod, bprod, maxx_prod});
    return maxx_prod;
}
int main()
{
    vector<int> A = {2,3,-1,4};
    cout<<Producter(A);
}