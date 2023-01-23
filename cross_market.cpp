#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases; i++)
    {
        int x, y;
        cin>>x>>y;
        if(x == 1 && y == 1) cout<<0<<endl;
        else cout<<x+y+min(x,y)-2<<endl;
    }
}