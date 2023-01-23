#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n;
        cin>>n;
        int first;
        cin>>first;
        int minn = first;
        for(int j=0; j<n-1; j++)
        {
            int x;
            cin>>x;
            minn = min(minn, x);
        }
        if(minn == first)
        {
            cout<<"Bob"<<endl;
        }
        else cout<<"Alice"<<endl;
    }
}