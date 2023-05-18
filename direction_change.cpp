#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n,m;
        cin>>n>>m;
        if(n ==1 || m==1)
        {
            if(n>=3 || m>=3) 
            {
                cout<<-1<<endl;
                continue;
            }
        }
        int x = min(n,m);
        int s = n-x+m-x;
        int t = s/2;
        int ans = 2*x+3*(t)+s-t-2;
        cout<<ans<<endl;
    }
}