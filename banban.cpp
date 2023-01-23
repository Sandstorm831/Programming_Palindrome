#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<1<<endl<<1<<" "<<2<<endl;
            continue;
        }
        int ops;
        if(n%2==0) ops = n/2;
        else ops = n/2+1;
        cout<<ops<<endl;
        for(int j=0; j<n/2; j++)
        {
            cout<<2+3*j<<" "<<3*n-3*j<<endl;
        }
        if(n%2 != 0) cout<<3*n/2+1<<" "<<3*n/2+2<<endl;
    }
}