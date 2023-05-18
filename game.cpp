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
        int first=0;
        int last = -2;
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            if(x == 0 && first==0) first = j;
            if(x == 0 && j>last) last = j;
        }
        cout<<last-first+2<<endl;
    }
}