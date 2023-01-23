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
        if(x%2 == y%2) cout<<"Tonya"<<endl;
        else cout<<"Burenka"<<endl;
    }
}