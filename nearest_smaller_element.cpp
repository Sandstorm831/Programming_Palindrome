// Problem Link - https://www.interviewbit.com/problems/nearest-smaller-element/
/* Problem Solution Function ----------------------------+
vector<int> Solution::prevSmaller(vector<int> &A) {    <-+
    stack<int> holder;
    vector<int> retriever;
    for (int i = 0; i < A.size(); i++)
    {
        while(!holder.empty())
        {
            if(A[i]>holder.top())
            {
                retriever.push_back(holder.top());
                holder.push(A[i]);
                break;
            } 
            else holder.pop();
        }
        if(holder.empty()){
            retriever.push_back(-1);
            holder.push(A[i]);
        }
    }
    return retriever;
}
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallElement(vector<int> A){
    stack<int> holder;
    vector<int> retriever;
    for (int i = 0; i < A.size(); i++)
    {
        while(!holder.empty())
        {
            if(A[i]>holder.top())
            {
                retriever.push_back(holder.top());
                holder.push(A[i]);
                break;
            } 
            else holder.pop();
        }
        if(holder.empty()){
            retriever.push_back(-1);
            holder.push(A[i]);
        }
    }
    return retriever;
    
}
int main()
{
    vector<int> A = { 34, 35, 27, 42, 5, 28, 39, 20, 28};
    vector<int> G = nextSmallElement(A);
    for (int i = 0; i < G.size(); i++)
    {
        cout<<G[i]<<" ";
    }
    
}