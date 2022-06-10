//Problem Link - https://www.interviewbit.com/problems/evaluate-expression/
/* Problem Solution Function
int Solution::evalRPN(vector<string> &A) {
    stack<int> numbers;
    for (int i = 0; i < A.size(); i++)
    {
        if(A[i] == "*")
        {
            int b = numbers.top(); numbers.pop();
            int a = numbers.top(); numbers.pop();
            numbers.push(a*b);
        }
        else if(A[i] == "-")
        {
            int a = numbers.top(); numbers.pop();
            int b = numbers.top(); numbers.pop();
            numbers.push(b-a);
        }
        else if(A[i] == "/")
        {
            int a = numbers.top(); numbers.pop();
            int b = numbers.top(); numbers.pop();
            numbers.push(b/a);
        }
        else if(A[i] == "+")
        {
            int a = numbers.top(); numbers.pop();
            int b = numbers.top(); numbers.pop();
            numbers.push(a+b);
        }
        else
        {
            numbers.push(stoi(A[i]));
        }
    }
    return numbers.top();
}

*/

#include <bits/stdc++.h>
using namespace std;
int evalRPN(vector<string> A){
    stack<int> numbers;
    for (int i = 0; i < A.size(); i++)
    {
        if(A[i] == "*")
        {
            int b = numbers.top(); numbers.pop();
            int a = numbers.top(); numbers.pop();
            numbers.push(a*b);
        }
        else if(A[i] == "-")
        {
            int a = numbers.top(); numbers.pop();
            int b = numbers.top(); numbers.pop();
            numbers.push(b-a);
        }
        else if(A[i] == "/")
        {
            int a = numbers.top(); numbers.pop();
            int b = numbers.top(); numbers.pop();
            numbers.push(b/a);
        }
        else if(A[i] == "+")
        {
            int a = numbers.top(); numbers.pop();
            int b = numbers.top(); numbers.pop();
            numbers.push(a+b);
        }
        else
        {
            numbers.push(stoi(A[i]));
        }
    }
    return numbers.top();
}
int main(){

}