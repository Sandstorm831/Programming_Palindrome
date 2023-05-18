#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        int orig = m;
        int j=0;
        vector<int> store(n,0);
        while(m>0 && j<n)
        {
            if(s[j] == '1' && orig%2 == 1)
            {
                m--;
                store[j]++;
            }
            else if(s[j] == '0' && orig%2 == 0)
            {
                m--;
                store[j]++;
            }
            j++;
        }
        if(m>0)
        {
            store[n-1]+=m;
        }
        for(int j=0; j<n; j++)
        {
            if((orig-store[j])%2==1)
            {
                if(s[j]=='0')s[j]='1';
                else s[j]='0';
            } 
        }
        cout<<s<<endl;
        for(int j=0; j<n; j++)
        {
            cout<<store[j]<<" ";
        }
        cout<<endl;
    }
}