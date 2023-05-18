#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases;i++)
    {
        int a, b;
        cin>>a>>b;
        int l=a, m=b;
        for(int j=0; j<a+b; j++)
        {
            if(l>0) cout<<0;
            if(m>0) cout<<1;
            l--;
            m--;
        }
        cout<<endl;
    }
}