#include <bits/stdc++.h>
using namespace std;
string fnc(string a, string b)
{
    string x = "";
    int i=0;
    while(i<a.size() && i<b.size())
    {
        if(a[i] == b[i]) x+=a[i];
        else break;
        i++;
    }
    return x;
}
int main()
{
    int n;cin>>n;
    vector<string> s(n);
    for(int i=0; i<n; i++) 
    {
        string x;cin>>x;
        transform(x.begin(), x.end(), x.begin(), ::tolower); 
        s[i] = x;
    }
    string com = s[0];
    for(int i=1; i<s.size(); i++)
    {
        com = fnc(s[i], com);
    }
    cout<<com<<endl;
}