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
        map<int,int> mp;
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            if(mp.find(x) == mp.end())
            {
                mp[x]=1;
            }
            else
            {
                if(mp[x]==2) continue;
                else mp[x]+=1;
            }
        }
        int summer=0;
        for(auto itr=mp.begin(); itr!=mp.end(); itr++)
        {
            summer+=itr->second;
        }
        if(summer%2==1) cout<<summer/2+1<<endl;
        else cout<<summer/2<<endl;
    }
}