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
        bool s=false;
        int xx=0;
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            if(x!=j && !s) 
            {
                s=true;
                xx = x;
            }
            else if(x!=j && s) xx &= x;
        }
        cout<<xx<<endl;
    }
}