#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a=0;
    cin>>n;
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        int a1, a2, a3;
        cin>>a1>>a2>> a3;
        cout<<endl;
        if (a1+a2+a3>=2)
        {
            a += 1;
        }
        else
        {
            a += 0;
        }   
    }
    cout<<a;

}