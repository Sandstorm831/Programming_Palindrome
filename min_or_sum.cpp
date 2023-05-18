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
        int ans=0;
        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            ans |= x;
        }
        cout<<ans<<endl;
    }
}