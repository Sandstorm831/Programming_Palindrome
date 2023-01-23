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
        if(n == 2) cout<<2<<" "<<1<<endl;
        else if(n == 3) cout<<-1<<endl;
        else
        {
            for(int j=3; j<=n; j++)
            {
                cout<<j<<" ";
            }
            cout<<2<<" "<<1<<endl;
        }
    }
}