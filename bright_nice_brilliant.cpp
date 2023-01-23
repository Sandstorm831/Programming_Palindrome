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
        for(int j=0;j<n;j++)
        {
            for(int k=0; k<=j; k++)
            {
                if(k == 0 || k==j) cout<<1<<" ";
                else cout<<0<<" ";
            }
            cout<<endl;
        }
    }
}