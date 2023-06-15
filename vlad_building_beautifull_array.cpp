#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases; i++)
    {
        int n;
        cin>>n;
        int ev=0, od=0;
        int minn = INT_MAX;
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            if(x%2==0) ev++;
            else od++;
            minn = min(minn, x);
        }
        if(ev == 0 || od == 0) cout<<"Yes"<<endl;
        else if(minn%2==1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}