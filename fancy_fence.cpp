#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cin>>a;
    for (int i = 0; i < a; i++)
    {
        int b;
        cin>>b;
        if (360%(180-b)==0)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        
        
    }
    
}