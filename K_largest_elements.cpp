// Problem link - https://www.interviewbit.com/problems/k-largest-elements/
#include<bits/stdc++.h>
using namespace std;
vector<int> priorelem(vector<int> A, int B){    
    priority_queue<int,vector<int>,greater<int>>que[B];
    for (int i = 0; i < B; i++)
    {
        que->push(A[i]);
    }
    for (int i = B; i < A.size(); i++)
    {
        if(que->top()<A[i]){que->pop();que->push(A[i]);}
    }
    vector<int> vec;
    for (int i = 0; i < B; i++)
    {
        vec.push_back(que->top());
        que->pop();
    }
    return vec;
}
int main()
{
    vector<int> A = {1,2,3,4,233,45,6,78,3,56,245}; // This has to be assuemd
    int k = 3;
    vector<int> B = priorelem(A,k);
    for (int i = 0; i < B.size(); i++)
    {
        cout<<B[i]<<" ";
    }
    
}
