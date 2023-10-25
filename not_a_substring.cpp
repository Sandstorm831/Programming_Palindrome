#include <bits/stdc++.h>
using namespace std;
bool checker(string s, string t)
{
    for(int i=0; i+s.length()-1<t.length(); i++)
    {
        if(t.substr(i,s.length()) == s) return true;
    }
    return false;
}
int main()
{
    int cases;cin>>cases;
    while(cases--)
    {
        string s;cin>>s;
        string dd, kk;
        for(int i=0; i<s.length();i++) dd+="(";
        for(int i=0; i<s.length();i++) dd+=")";
        for(int i=0; i<s.length();i++) kk+="()";
        if(!checker(s, dd)) cout<<"Yes"<<endl<<dd<<endl;
        else if(!checker(s, kk)) cout<<"Yes"<<endl<<kk<<endl;
        else cout<<"No"<<endl;
    }
}