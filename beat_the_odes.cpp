#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int j=0; j<cases; j++)
    {
        int n;
        cin>>n;
        int ev=0;
        int od=0;
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            if(x%2==0)ev++;
            else od++;
        }
        cout<<min(ev,od)<<endl;
    }
}