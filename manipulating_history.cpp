#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases;i++)
    {
        int n;
        cin>>n;
        vector<int> v(27,0);
        for(int j=0; j<2*n+1; j++)
        {
            string s;
            cin>>s;
            for(int k=0; k<s.length(); k++)
            {
                int n = s[k]-'a'+1;
                v[n]++;
            }
        }
        int x;
        for(int j=1; j<v.size(); j++)
        {
            if(v[j]%2==1) x=j;
        }
        char t = (x-1)+'a';
        cout<<t<<endl;
    }
}