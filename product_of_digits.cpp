#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int c=1;
    int a = s.length();
    for (int i = 0; i < a; i++)
    {
        c=c*(s[i]-48);
    }
    cout<<c;
}