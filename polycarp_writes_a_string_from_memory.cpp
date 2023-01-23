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
        set<char> sety;
        int counter=1;
        for(int j=0; j<s.length(); j++)
        {
            sety.insert(s[j]);
            if(sety.size()>3)
            {
                sety.clear();
                j--;
                counter++;
            }
        }
        cout<<counter<<endl;
    }
}