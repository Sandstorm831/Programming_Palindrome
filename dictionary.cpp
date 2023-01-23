#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        char first, second;
        cin>>first>>second;
        int fn = first-'a';
        int sn = second-'a';
        if(fn>sn) cout<<25*fn+sn+1<<endl;
        else cout<<25*fn+sn<<endl;
    }
}