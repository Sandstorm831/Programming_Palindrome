#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    if (s[0]>92)
    {
        s[0] = s[0]-32;
    }
    else
    {
        s[0] = s[0];
    }
    cout<<s;
}