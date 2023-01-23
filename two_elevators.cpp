#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        int first = abs(a-1);
        int second = abs(c-b)+abs(c-1);
        if(first>second) cout<<2<<endl;
        else if(second>first) cout<<1<<endl;
        else if(second == first) cout<<3<<endl;
    }
}