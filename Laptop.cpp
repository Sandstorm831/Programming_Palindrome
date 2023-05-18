#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin>>a>>b;
        if (b>a)
        {
            m+=1;
        }
        
    }
    if (m>0)
    {
        cout<<"Happy Alex";
    }
    else
    {
        cout<<"Poor Alex";
    }   
}