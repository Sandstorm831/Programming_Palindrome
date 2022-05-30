// Problem Link - https://www.interviewbit.com/problems/allocate-books/
#include <bits/stdc++.h>
using namespace std;
    bool ispossible(vector<int> A, int size, int B, int mid){
        int studentcount = 1, runningmess = 0;
        for (int i = 0; i < size+1; i++)
        {
            if (A[i]>mid)
            {
                return false;
            }
            if (runningmess+A[i]>mid)
            {
                studentcount++;
                runningmess = A[i];
                if(studentcount>B) return false;
            }
            else
            {
                runningmess += A[i];
            }
        }
        
        return true;
        

    }
int books(vector<int> A, int B){
    int min = 0;
    long long max=0;
    for (int i = 0; i < A.size(); i++)
    {
        max += A[i];
    }
    int result = INT_MAX;
    int size = A.size()-1;
    int mid = (min+max)/2;
    if(size+1<B) return -1;
    while(min<=max){
        mid = (min+max)/2;
        if (ispossible(A, size, B,mid))
        {
            result = mid;
            max = mid-1;
        }
        else
        {
            min = mid+1;
        }
    }
    return result;
    
}
int main()
{
    vector<int> A = {12, 34, 67, 90};
    cout<<books(A,2);


}