// Problem Link - https://www.interviewbit.com/problems/trailing-zeros-in-factorial/
#include <bits/stdc++.h>
using namespace std;
int trailor(int A)
{
    int lor = A;
    int capturer=0;
    int i =1;
    while(lor > 0)
    {
        lor = A;
        capturer += A/pow(5,i);
        i++;
        lor = A/pow(5,i);
    }
    return capturer;
}
int main()
{
    
}