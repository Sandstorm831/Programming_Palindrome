#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        if(y1 != y2 && y2!=y3 && y1!=y3) cout<<0<<endl;
        else if(y1 == y2 && y3<y1) cout<<abs(x1-x2)<<endl;
        else if(y2==y3 && y1<y2) cout<<abs(x2-x3)<<endl;
        else if(y3 == y1 && y2<y3) cout<<abs(x3-x1)<<endl;
        else cout<<0<<endl;
    }
}