#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int x,y;
        cin>>x>>y;
        if(y%4 == 0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        if(y%2 != 0)
        {
            for(int j=0; j<x; j+=2)
            {
                cout<<j+1<<" "<<j+2<<endl;
            }
            continue;
        }
        else
        {
            for(int j=0; j<x; j+=4)
            {
                cout<<j+2<<" "<<j+1<<endl;
            }
            for(int j=2; j<x; j+=4)
            {
                cout<<j+1<<" "<<j+2<<endl;
            }
            continue;
        }
    }
}