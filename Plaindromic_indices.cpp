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
        string s;
        cin>>s;
        int x = n/2;
        char t = s[x];
        char orig = t;
        int counter=0;
        while(t == orig)
        {
            counter++;
            x++;
            t = s[x];
        }
        if(n%2==0) cout<<2*counter<<endl;
        else cout<<2*counter-1<<endl;
    }
}