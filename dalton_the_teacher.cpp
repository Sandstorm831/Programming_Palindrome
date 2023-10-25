#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;cin>>cases;
    while(cases--)
    {
        int counter=0;
        int n;cin>>n;
        for(int i=1; i<=n; i++)
        {
            int x;cin>>x;
            if(x == i) counter++;
        }
        if(counter%2 == 1) cout<<(counter/2) + 1<<endl;
        else cout<<counter/2<<endl;
    }
}