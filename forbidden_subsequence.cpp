#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        string a,b;
        cin>>a>>b;
        sort(a.begin(), a.end());
        if(b!="abc")
        {
            cout<<a<<endl;
            continue;
        }
        else
        {
            int aa=0,bb=0, cc=0;
            int diff = a.length();
            for(int j=0; j<a.length(); j++)
            {
                if(a[j]!='a' && a[j] != 'b' && a[j] != 'c')
                {
                    diff = j;
                    break;
                } 
                else if(a[j] == 'a') aa++;
                else if(a[j] == 'b') bb++;
                else if(a[j] == 'c') cc++;
            }
            // cout<<aa<<bb<<cc<<endl;
            string ans="";
            for(int j=0; j<aa; j++) ans+='a';
            for(int j=0; j<cc; j++) ans+='c';
            for(int j=0; j<bb; j++) ans+='b';
            // cout<<ans<<" | ";
            ans+=a.substr(diff);
            if(aa>0 && bb>0 && cc>0) cout<<ans<<endl;
            else cout<<a<<endl;
            continue;
        }
    }
}