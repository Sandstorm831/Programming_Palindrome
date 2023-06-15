#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cases;
    cin>>cases;
    while(cases--)
    {
        long long n; cin>>n;
        unordered_map<long long,multiset<long long>> mp;
        for(long long i=0; i<n; i++)
        {
            long long a,b; cin>>a>>b;
            mp[a].insert(-b);
        }
        long long ans=0;
        long long count=0;
        for(long long i=1; i<=n; i++)
        {
            if(mp.find(i)!=mp.end())
            {
                count=i;
                for(auto itr = mp[i].begin(); itr!= mp[i].end() && count>0; itr++)
                {
                    ans += -(*itr);
                    count--;
                }
            }
        }
        cout<<ans<<endl;
    }
}