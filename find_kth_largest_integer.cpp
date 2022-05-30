#include<bits/stdc++.h>
using namespace std;
int priorelem(vector<int> A, int k){
    priority_queue<int,vector<int>,greater<int>>que[k];
    for (int i = 0; i < k; i++)
    {
        que->push(A[i]);
    }
    for (int i = k; i < A.size(); i++)
    {
        if(que->top()<A[i]){que->pop();que->push(A[i]);}
    }
    return que->top();
}
int main()
{
    vector<int> A = {1,2,3,4,233,45,6,78,3,56,245};
    int k = 3;
    cout<<priorelem(A,k);

}