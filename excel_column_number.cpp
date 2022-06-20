// Problem Link - https://www.interviewbit.com/problems/excel-column-number/
#include <bits/stdc++.h>
using namespace std;
int titleToNumber(string A)
{
    int size = A.size();
    int dupe = size;
    int turner = 0;
    for (int i = 0; i < size; i++)
    {
        turner += pow(26,(dupe-1))*(int(A[i])-64);
        dupe--;
    }
    return turner;
    
}
int main()
{

}