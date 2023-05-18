#include <bits/stdc++.h>
using namespace std;
char finder(char a, char b)
{
    char x = 'a';
    for(int i=0; i<26; i++)
    {
        if(x != a && x != b) return x;
        else x++;
    }
}
int main()
{
    string s;
    cin>>s;
    for(int j=1; j<s.length(); j++)
    {
        if(s[j] == s[j-1])
        {
            // cout<<s[j-1]<<" "<<s[j]<<" "<<s[j+1]<<endl;
            char x = finder(s[j-1], s[j+1]);
            s[j] = x;
        }
    }
    cout<<s<<endl;

}