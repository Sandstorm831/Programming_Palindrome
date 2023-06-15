#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        string s;
        cin>>s;
        int x = 0;
        string bs = "";
        for(int j=0; j<s.length(); j++)
        {
            if(s[j] == '?') bs+=x+'0';
            else 
            {
                bs += s[j];
                x = s[j]-'0';
            }
        }
        cout<<bs<<endl;
    }
}