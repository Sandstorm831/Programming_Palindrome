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
        if(n%2==1)
        {
            for(int j=0; j<n; j++)
            {
                cout<<1<<" ";
            }
        }
        else
        {
            cout<<3<<" "<<1;
            for(int j=0; j<n-2; j++)
            {
                cout<<" "<<2;
            }
        }
        cout<<endl;
    }
}