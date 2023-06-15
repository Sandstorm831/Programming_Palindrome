#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cases;
    cin>>cases;
    while(cases--)
    {
        long long n, k; cin>>n>>k;
        vector<long long> v;unordered_map<long long,long long> mp,ump;
        long long ans=0;
        for(long long i=0; i<n; i++)
        {
            long long x; cin>>x;
            mp[x]=0;
            v.push_back(x);
        }
        for(long long i=1; i<=k; i++)
        {
            long long a,b;cin>>a>>b;
            a--;
            long long mm = v[a];
            if(v[a] == b) continue;
            if(ump.find(mm) == ump.end()) ump[mm] = i-mp[mm];
            else ump[mm] += i-mp[mm];
            mp.erase(mm);mp[b]=i;
            v[a]=b;
        }
        for(auto itr=mp.begin(); itr!=mp.end(); itr++)
        {
            if(ump.find(itr->first) == ump.end()) ump[itr->first] = k+1-itr->second;
            else ump[itr->first] += k+1-itr->second;
        }
        long long tot = (k+1);
        ans=0;
        for(auto itr = ump.begin(); itr != ump.end(); itr++)
        {
            ans += ((tot-itr->second) * (itr->second)) + ((itr->second)*(itr->second-1))/2;
        }   
        cout<<ans<<endl;
    }
}