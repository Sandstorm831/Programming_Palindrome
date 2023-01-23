#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int df, cf, of, d, c;
        cin>>df>>cf>>of>>d>>c;
        int res = max(0,d-df)+max(0,c-cf);
        int final = of-res;
        if(final >= 0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}