// Problem Link - https://www.interviewbit.com/problems/first-missing-integer/
#include <bits/stdc++.h>
using namespace std;
void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int firstMissingPossitive(vector<int> A)
{
    int n=A.size();
    int j=0;
    for(int i=0;i<n;i++){
        if(A[i]<=0){
            swap(A[i],A[j]);
            j++;
        }
    }
    for(int i=j;i<n;i++){
        if(abs(A[i])+j-1>=0&&abs(A[i])+j-1<n){
         if(A[abs(A[i])+j-1]>0)
           A[abs(A[i])+j-1]=-A[abs(A[i])+j-1];
        }
    }
    for(int i=j;i<n;i++){
       // cout<<A[i]<<"\n";
        if(A[i]>0)
         return (i-j+1);
    }
    return (n-j+1);
}
int main()
{
}
