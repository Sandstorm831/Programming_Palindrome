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
        int l=0;
        if(n%2==1)
        {
            cout<<1<<" ";
            l=1;
        }
        for(int j=0; j<n/2; j++)
        {
            cout<<l+2<<" "<<l+1<<" ";
            l+=2;
        }
        cout<<endl;
    }
}