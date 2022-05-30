// Problem link - https://www.interviewbit.com/problems/priority_queue/
#include <bits/stdc++.h>
using namespace std;
int hel(vector<int> A)
{
    priority_queue<int,vector<int>,greater<int>>que;
    int size = A.size();
    for(int i=0;i<size;i++)
    {
        que.push(A[i]);
    }
    int cost =0;
    while(que.size()>1)
    {
        int first = que.top();
        que.pop();
        int second = que.top();
        que.pop();
        int ans = first+second;
        cost += ans;
        que.push(ans);
    }
    return cost;
}
int main()
{
    vector<int> A = {2,5,4,8,6,9}; //  This has to be assumed
    cout<<hel(A);
}