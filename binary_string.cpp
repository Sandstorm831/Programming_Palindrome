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
        vector<int> cml;
        cml.push_back(0);
        for(int j=0; j<s.length(); j++)
        {
            if(s[j] == '1') cml.push_back(cml.back()+1);
            else cml.push_back(cml.back());
        }
        int ans = cml.back();
        for(int j=0; j+cml.back()<=s.length(); j++)
        {
            ans=min(ans, cml.back()-cml[j+cml.back()]+cml[j]);
        }
        cout<<ans<<endl;
    }
}