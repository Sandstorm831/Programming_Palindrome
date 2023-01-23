#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        bool state=false;
        string s;
        cin>>s;
        char next;
        if(s[0] == 'Y') next = 'e';
        else if(s[0] == 'e') next = 's';
        else if(s[0] == 's') next = 'Y';
        else next = 'z';
        for(int j=1; j<s.length(); j++)
        {
            if(next == 'z') 
            {
                cout<<"NO"<<endl;
                break;
            }
            if(next == s[j])
            {
                if(s[j] == 'Y') next = 'e';
                else if(s[j] == 'e') next = 's';
                else if(s[j] == 's') next = 'Y';
                else next == 'z';
            }
            else 
            {
                cout<<"NO"<<endl;
                break;
            }
            if(j == s.length()-1) state=true;
        }
        if(s.length()==1 && next=='z') cout<<"NO"<<endl;
        else if(s.length()==1 && next != 'z') cout<<"YES"<<endl;
        if(state) cout<<"YES"<<endl;
    }
}