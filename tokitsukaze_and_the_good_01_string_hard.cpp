#include<bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases;i++)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ns;
        int minn = 0;
        char prev='2';
        int counter=0;
        for(int j=0; j<s.length(); j+=2)
        {
            if(s[j]!=s[j+1]) minn++;
            else 
            {
                if(prev != s[j]) counter++;
                prev = s[j];
            } 
        }
        cout<<minn<<" "<<max(1,counter)<<endl;
    }
}