#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0; i<cases; i++)
    {
        long long n;
        cin>>n;
        long long mod=1e9+7;
        vector<long long> pos(n);
        for(long long j=0; j<n; j++)
        {
            long long x;
            cin>>x;
            pos[x]=j;
        }
        long long s = min(pos[0], pos[1]);
        long long l =  max(pos[0], pos[1]);
        long long counter=1;
        for(long long j=2; j<n; j++)
        {
            if(pos[j]>l)
            {
                l = pos[j];
            }
            else if(pos[j]<s)
            {
                s = pos[j];
            }
            else
            {
                counter=((counter%mod)*((l-s+1)-j)%mod)%mod;
            }
        }
        cout<<counter<<endl;
    }
}