// Problem link -> https://www.interviewbit.com/problems/reverse-bits/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned int A=3;
    int a[32];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < 32; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    for(int i=0; i<32; i++){
        if((A&(1<<i)) != 0){
            a[i] +=1;
        }
    }

    for (int i = 0; i < 32; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    unsigned res = 0;
    for(int i=0; i<32; i++){
        res += (a[31-i])*(1<<i);
    }
    cout<<res;

}