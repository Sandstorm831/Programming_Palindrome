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
        unordered_set<int> orig;
        unordered_set<int> altar;
        string s;
        cin>>s;
        for(int j=1; j<=n;j++)
        {
            int x=s[j-1]-'0';
            // cout<<x<<endl;
            if(x==0) altar.insert(j);
            orig.insert(j);
        }
        int z=0;
        long long counter=0;
        for(int j=1;j<=n; j++)
        {
            if(altar.find(j) == altar.end()) continue;
            else
            {
                // altar.erase(altar.find(j));
                if(orig.find(j) != orig.end())
                {
                    orig.erase(orig.find(j));
                    counter+=j;
                }
                int y=2;
                while(altar.find(y*j) != altar.end())
                {
                    if(orig.find(y*j) != orig.end())
                    {
                        orig.erase(orig.find(y*j));
                        counter+=j;
                    }
                    y++;
                }
            }
        }
        cout<<counter<<endl;
    }
}