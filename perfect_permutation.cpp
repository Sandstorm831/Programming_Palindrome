#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases;i++)
    {
        int n;
        cin>>n;
        if(n==1) cout<<1<<endl;
        else
        {
            for(int j=2; j<=n; j++)
            {
                cout<<j<<" ";
            }
            cout<<1<<endl;
        }
    }
}