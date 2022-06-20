// Problem Link - https://www.interviewbit.com/problems/next-smallest-palindrome/
#include <bits/stdc++.h>
using namespace std;
bool compare(string a, string newer){
    if(a.size()<newer.size()) return true;
    for (int i = 0; i < newer.size(); i++)
    {
        if(a[i]>newer[i]) return false;
        if(a[i]<newer[i]) return true;
    }
    return false;
}
string solver(string A)
{
    string newer = "";
    int size = A.size();
    for (int i = 0; i < size; i++)
    {
        if(i <= size/2 -1 ) newer += A[i];
        else newer += A[size-1-i];
    }
    // cout<<newer;
    while(!compare(A,newer))
    {
        size = newer.size();
        int mediator = newer.size()/2;
        // cout<<newer.size();
        while (mediator < size)
        {
            if(int(newer[mediator])!=9+48)
            {
                int inty = int(newer[mediator]);
                newer[mediator] = inty+1;
                newer[size-mediator-1] = inty+1;
                break;
            }
            else
            {
                newer[mediator] = 48;
                newer[size-mediator-1] = 48;
                // cout<<newer;
                mediator++;
            }
        }
        if(newer[0] =='0')
        {
            char c = '1';
            newer[0] = 48+1;
            newer += c;
            break;
            cout<<"here";
            // cout<<newer[0]<<newer[1]<<endl;
        }
        // cout<<newer[0]<<endl;
    }
    // cout<<newer;
    return newer;
}
int main()
{
    string A = "9";
    string s = solver(A);
}