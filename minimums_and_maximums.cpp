#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int l,r,n,m;
        cin>>l>>r>>n>>m;
        if(r<n || m<l) cout<<l+n<<endl;
        else cout<<max(l,n)<<endl;
    }
}