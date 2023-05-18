#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n, r, b;
        cin>>n>>r>>b;
        int x = b+1;
        int c = ceil(double(r)/double(x));
        int t = c*x-r;
        while(b>0)
        {
            if(t>0)
            {
                for(int j=0; j<c-1; j++)
                {
                    cout<<'R';
                }
                cout<<'B';
                b--;
                r-=c-1;
                t--;
            }
            else
            {
                for(int j=0; j<c; j++) 
                {
                    cout<<'R';
                }
                cout<<'B';
                b--;
                r-=c;
            }
        }
        for(int j=0; j<r; j++)
        {
            cout<<'R';
        }
        cout<<endl;
    }
}