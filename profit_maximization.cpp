//Problem link - https://www.interviewbit.com/problems/profit-maximisation/
#include <bits/stdc++.h>
using namespace std;
int hel(vector<int> A, int B)
{
    priority_queue<int>que;
    int size = A.size();
    for(int i=0;i<size;i++)
    {
        que.push(A[i]);
    }
    int k = B;
    int cost =0;
    while(k>0)
    {
        int first = que.top();
        que.pop();
        cost += first;
        first -=1;
        que.push(first);
        k--;

    }
    return cost;
}
int main()
{
    vector<int> A = {2,5,4,8,6,9}; //  This has to be assumed
    int b = 4
    cout<<hel(A,b);
}