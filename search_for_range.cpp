// Problem link - https://www.interviewbit.com/problems/search-for-a-range/
#include <bits/stdc++.h>
using namespace std;
vector<int> searchange(vector<int> A, int B) {
    int n = A.size();
    int low = 0;
    int high = n-1;
    int mid = (low+high)/2;
    vector<int>v(2);
    v[0] = -1; v[1] = -1;
    while (low<=high)
    {
        mid = (low+high)/2;
        if (A[mid]==B)
        {
            v[0] = mid;
            high = mid-1;
        }
        else if(A[mid]<B) low=mid+1;
        else high=mid-1;
    }
    if (v[0]== -1)
    {
        return v;
    }
    low = v[0];
    high = n-1;
    while (low<=high)
    {
        mid = (low+high)/2;
        if(A[mid==B])
        {
            v[1] = mid;
            low = mid+1;
        }
        else if(A[mid]<B) low=mid+1;
        else high=mid-1;
    }
    return v;
    
    
}
int main(){
    vector<int> A = {1, 1, 1, 1, 1, 1, 1, 1 , 10, 10, 10, 10, 10, 10, 10, 10 }; // This has to be assumed
    vector<int> B = searchange(A, 10);
    for (int i = 0; i < B.size(); i++)
    {
        cout<<B[i]<<" ";
    }
}