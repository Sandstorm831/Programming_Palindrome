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
        string new_str="";
        for(int j=0; j<s.length(); j++)
        {
            char a = s[j];
            new_str += a;
            new_str += a;
        }
        for(int j=0; j<s.length(); j++)
        {
            int alter = new_str.length()-j-1;
            if(j%2==0)
            {
                new_str[alter] = new_str[j];
            }
            else{
                new_str[j] = new_str[alter];
            }
        }
        cout<<new_str<<endl;
    }
}