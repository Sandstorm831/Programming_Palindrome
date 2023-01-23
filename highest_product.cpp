// Problem Link - https://www.interviewbit.com/problems/highest-product/
#include <bits/stdc++.h>
using namespace std;
int maxp3(vector<int> &A) {
    priority_queue<int, vector<int>, greater<int>> pq;
    priority_queue<int> qp;
    int counter=0;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]<0 && counter<2)
        {
            qp.push(A[i]);
            counter++;
        }
        else if(A[i]<0 && qp.top()>A[i])
        {
            qp.pop();
            qp.push(A[i]);
        }
    }
    pq.push(A[0]); pq.push(A[1]); pq.push(A[2]);
    for(int i=3; i<A.size(); i++)
    {
        if(pq.top()<A[i])
        {
            pq.pop();
            pq.push(A[i]);
        }
    }
    int multi;
    multi = pq.top(); pq.pop();         
    multi*=pq.top(); pq.pop();
    multi*=pq.top();
    if(counter!=2) return multi;
    int mtr = pq.top();
    int multer = qp.top();qp.pop();
    multer*=qp.top();
    multer*=mtr;
    return max(multer, multi);
}