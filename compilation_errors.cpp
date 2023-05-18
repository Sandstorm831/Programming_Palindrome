#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b=0,c=0, e=0;
    cin>>a;
    for (int i = 0; i < a; i++)
    {
        int d;
        cin>>d;
        b+=d;
    }
    for (int i = 0; i < a-1; i++)
    {
        int d;
        cin>>d;
        c+=d;
    }
    for (int i = 0; i < a-2; i++)
    {
        int d;
        cin>>d;
        e+=d;
    }
    cout<<b-c<<endl<<c-e;
    
}