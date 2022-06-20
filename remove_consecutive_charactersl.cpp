// Problem Link - https://www.interviewbit.com/problems/remove-consecutive-characters/
/* Problem Solution Function --------------------------------+
string Solution::solve(string A, int B) {      <-------------+
    int counter = 1;
    char ident = A[0];
    for (int i = 1; i < A.size(); i++)
    {/
+        if(ident == A[i])
        {
            counter++;
            if(counter == B)
            {
                A.erase(i-B+1, B);
                counter = 0;
                i = i-B;
                continue;
            }
        }
        else{
            counter = 1;
            ident = A[i];
        }
    }
    return A;
}
*/
#include <bits/stdc++.h>
using namespace std;
string slover(string A, int B);
{
    int counter = 1;
    char ident = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        if(ident == A[i])
        {
            counter++;
            if(counter == B)
            {
                A.erase(i-B+1, B);
                counter = 0;
                i = i-B;
                continue;
            }
        }
        else{
            counter = 1;
            ident = A[i];
        }
    }
    return A;
}
int main()
{}