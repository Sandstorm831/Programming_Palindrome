#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n;
        string s;
        cin>>n>>s;
        if(n>2)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else if(n == 1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        else
        {
            if(s[0] == s[1])
            {
                cout<<"NO"<<endl;
            }
            else cout<<"Yes"<<endl;
            continue;
        }
    }
}