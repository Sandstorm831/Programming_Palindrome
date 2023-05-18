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
        int n = s.length();
        vector<int> v(26,0);
        int j;
        for(j=0; j<n; j++)
        {
            char k = s[j];
            if(v[k-'a']==0)
            {
                v[k-'a']=1;
            }
            else break;
        }
        bool ans=true;
        for(int l=j; l<n; l++)
        {
            if(s[l-j]==s[l]) continue;
            else
            {
                ans=false;
                break;
            }
        }
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}