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
        string s;
        cin>>s;
        int counter=0;
        int fed = 0;
        for(int j=0; j<n; j++)
        {
            if(s[j] == '0')
            {
                counter+=fed;
                fed=2;
                continue;
            }
            else
            {
                fed--;
                fed = max(0, fed);
            }
        }
        cout<<counter<<endl;
    }
}