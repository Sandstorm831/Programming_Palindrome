// Problem Link - https://www.interviewbit.com/problems/balanced-parantheses/
/*Problem solution function ---------+
int Solution::solve(string A) {    <-+
    stack<char> well;
    int size = A.size();
    for (int i = 0; i < size; i++)
    {
        if(A[i] == '(') well.push(A[i]);
        else if(!well.empty()) well.pop();
        else return false;
    }
    return well.empty();
}
*/
#include <bits/stdc++.h>
using namespace std;
bool parenthesisbalancer(string A)
{
    stack<char> well;
    int size = A.size();
    for (int i = 0; i < size; i++)
    {
        if(A[i] == '(') well.push(A[i]);
        else if(!well.empty()) well.pop();
        else return false;
    }
    return well.empty();

}
int main()