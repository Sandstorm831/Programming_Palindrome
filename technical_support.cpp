#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n;
        cin>>n;
        string str;
        cin>>str;
        int counter=0;
        for(int j=0; j<str.length(); j++)
        {
            if(str[j] == 'Q') counter++;
            else counter = max(0,counter-1);
        }
        if(counter > 0) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}