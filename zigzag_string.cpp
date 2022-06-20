// Problem Link - https://www.interviewbit.com/problems/zigzag-string/
/* Problem Solution Function --------------------------+
string Solution::convert(string A, int B) {     <------+
    if(B == 1 || A.size() <= B) return A;
    int defencerone = 2*B, defencertwo = -2;
    string offencer = "";
    for (int j = 0; j < B; j++)
    {
        int i = j;
        defencerone -= 2; defencertwo += 2;
        offencer += A[i];
        while(i+defencerone < A.size())
        {
            if(defencerone > 0) offencer += A[defencerone + i];
            if(defencertwo > 0 && i+defencerone+defencertwo <A.size()) offencer += A[defencerone + defencertwo + i];
            i = i+defencerone+defencertwo;
        }

    }
    return offencer;
}
*/
#include <bits/stdc++.h>
using namespace std;
string convert(string A, int B)
{
    if(B == 1 || A.size() <= B) return A;
    int defencerone = 2*B, defencertwo = -2;
    string offencer = "";
    for (int j = 0; j < B; j++)
    {
        int i = j;
        defencerone -= 2; defencertwo += 2;
        offencer += A[i];
        while(i+defencerone < A.size())
        {
            if(defencerone > 0) offencer += A[defencerone + i];
            if(defencertwo > 0 && i+defencerone+defencertwo <A.size()) offencer += A[defencerone + defencertwo + i];
            i = i+defencerone+defencertwo;
        }

    }
    return offencer;
}
int main()
{
    string A = "ABCDEFGHIJKLMNOPQRS";
    int B = 6;
    cout<<endl<<convert(A,B);
}