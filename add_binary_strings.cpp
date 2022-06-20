// Problem Link - https://www.interviewbit.com/problems/add-binary-strings/
/* Problem Solution Function -------------------------------------+
string Solution::addBinary(string A, string B) {      <-----------+
    if(A.empty()) return B;
    else if(B.empty()) return A;
    if(A.size() > B.size()) B.insert(0,A.size()-B.size(),'0');
    else if(B.size() > A.size()) A.insert(0,B.size()-A.size(),'0');
    string finaler = "";
    int medior = 0;
    for (int i = A.size()-1; i >= 0; i--)
    {
        string appender = " ";
        appender[0] = ((A[i]-48)^(B[i]-48)^medior)+48;
        finaler += appender[0];
        if(A[i]-48+B[i]-48+medior > 1) medior = 1;
        else medior = 0;
    }
    if(medior == 1) finaler += 49;
    reverse(finaler.begin(), finaler.end());
    return finaler;
}
*/
#include <bits/stdc++.h>
using namespace std;
strgin addBinary(string A, string B)
{
    if(A.empty()) return B;
    else if(B.empty()) return A;
    if(A.size() > B.size()) B.insert(0,A.size()-B.size(),'0');
    else if(B.size() > A.size()) A.insert(0,B.size()-A.size(),'0');
    string finaler = "";
    int medior = 0;
    for (int i = A.size()-1; i >= 0; i--)
    {
        string appender = " ";
        appender[0] = ((A[i]-48)^(B[i]-48)^medior)+48;
        finaler += appender[0];
        if(A[i]-48+B[i]-48+medior > 1) medior = 1;
        else medior = 0;
    }
    if(medior == 1) finaler += 49;
    reverse(finaler.begin(), finaler.end());
    return finaler;
}