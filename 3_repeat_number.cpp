// Problem Link - https://www.interviewbit.com/problems/n3-repeat-number/
#include <bits/stdc++.h>
using namespace std;
int repeatedNumber(vector<int> A)
{
    int size = A.size();
    int elemone = INT_MAX; 
    int elemtwo = INT_MAX;
    int counterone = 0; 
    int countertwo = 0;  
    for (int i = 0; i < size; i++)
    {
        if(counterone>0 && elemone == A[i]) counterone++;
        else if(countertwo>0 && elemtwo == A[i]) countertwo++;
        else if(counterone == 0)
        {
            elemone = A[i];
            counterone++;
        } 
        else if(countertwo == 0)
        {
            elemtwo = A[i];
            countertwo++;
        }
        else
        {
            counterone--;
            countertwo--;
        }
    }
    if(counterone == 0 && countertwo == 0)
    {
        return -1;
    }
    counterone = 0;
    countertwo = 0;
    for (int i = 0; i < size; i++)
    {
        if(A[i] ==  elemone) counterone++;
        else if(A[i] == elemtwo) countertwo++
    }
    if(counterone > size/3) return elemone;
    else if( countertwo > size/3) return elemtwo;
    else return -1;
    
}
int main()
{}