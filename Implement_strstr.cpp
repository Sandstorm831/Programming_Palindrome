// Problem Link - https://www.interviewbit.com/problems/implement-strstr/
/*Problem Solution Function ----------------------------+
bool string_checker(string A, string B, int hack)  <----+
{
    for (int j = 0; j < B.size(); j++)
    {
        if(A[hack+j] != B[j]) return false;
    }
    return true;
}
int Solution::strStr(const string A, const string B) {
    if(B.empty() || A.empty() || B.size()>A.size()) return -1;
    for (int i = 0; i < A.size()-B.size()+1; i++)
    {
        if(string_checker(A,B,i)) return i;
    }
    return -1;
}
*/
#include <bits/stdc++.h>
using namespace std;
bool string_checker(string A, string B, int hack)
{
    for (int j = 0; j < B.size(); j++)
    {
        if(A[hack+j] != B[j]) return false
    }
    return true;
    
}
int strstr(string A, string B)
{
    if(B.empty() || A.empty()) return -1;
    for (int i = 0; i < A.size()-B.size()+1; i++)
    {
        if(string_checker(A,B,i)) return i;
    }
    return -1;
    
}