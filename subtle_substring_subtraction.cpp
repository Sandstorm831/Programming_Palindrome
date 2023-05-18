#include <bits/stdc++.h>
using namespace std;
int main()
{DROP TABS HERE TO MOVE THEM TO AN ADDITIONAL WINDOW
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        string s;
        cin>>s;
        if(s.length()==1)
        {
            cout<<"Bob "<<s[0]-'a'+1<<endl;
            continue;
        }
        int summer=0;
        for(int j=0; j<s.length(); j++)
        {
            summer+=s[j]-'a'+1;
        }
        if(s.length()%2==0)
        {
            cout<<"Alice "<<summer<<endl;
        }
        else cout<<"Alice "<<summer-2*min(s[0]-'a'+1, s.back()-'a'+1)<<endl;
    }
}