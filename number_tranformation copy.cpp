#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int x, y;
        cin>>x>>y;
        if(y%x != 0)
        {
            cout<<0<<" "<<0<<endl;
            continue;
        }
        else
        {
            int q = y/x;
            double sqt = sqrt(q);
            if(sqt == int(sqt)) cout<<2<<" "<<sqt<<endl;
            else cout<<1<<" "<<q<<endl;
        }
    }
}