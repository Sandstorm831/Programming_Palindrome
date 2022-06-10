// Problem Link - https://www.interviewbit.com/problems/redundant-braces/
/* Problem solution Function ----------+
int Solution::braces(string A) {   <---+
    string B = "";
    for (int i = 0; i < A.size(); i++)
    {
        if(A[i] == '(' || A[i] == ')' || A[i] == '+' ||A[i] ==  '-' ||A[i] ==  '*' ||A[i] ==  '/') 
        {
            B += A[i];
        }
    }

    stack<char> overflower;
    int streak = 0;
    for (int i = 0; i < B.size(); i++)
    {
        if( B[i] != ')')
        {
            overflower.push(B[i]);
            if(streak = 1) streak =0;
        }
        else
        {
            if(B[i-1] == '(') return 1;
            while(overflower.top() != '(')
            {
                overflower.pop();
                if(streak == 1) streak =0;
            }
            overflower.pop();
            if(streak == 1) 
            {
                return 1;
                break;
            }
            streak = 1;
        }
        
    }
    return 0;
}

*/
#include <bits/stdc++.h>
using namespace std;
int redundancy(string A){
    string B = "";
    for (int i = 0; i < A.size(); i++)
    {
        if(A[i] == '(' || A[i] == ')' || A[i] == '+' ||A[i] ==  '-' ||A[i] ==  '*' ||A[i] ==  '/') 
        {
            B += A[i];
        }
    }

    stack<char> overflower;
    int streak = 0;
    for (int i = 0; i < B.size(); i++)
    {
        if( B[i] != ')')
        {
            overflower.push(B[i]);
            if(streak = 1) streak =0;
        }
        else
        {
            if(B[i-1] == '(') return 1;
            while(overflower.top() != '(')
            {
                overflower.pop();
                if(streak == 1) streak =0;
            }
            overflower.pop();
            if(streak == 1) 
            {
                return 1;
                break;
            }
            streak = 1;
        }
        
    }
    return 0;
}
int main(){
    string A = "(a)";
    cout<<redundancy(A);

}