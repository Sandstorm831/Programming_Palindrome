#include <bits/stdc++.h>
using namespace std;
int  main()
{
    long long cases;
    cin>>cases;
    for(long long i=0; i<cases; i++)
    {
        long long n;
        cin>>n;
        vector<long long> v;
        for(long long j=0; j<n; j++) 
        {
            long long x;
            cin>>x;
            v.push_back(x);
        }
        vector<long long> stored(n,0);
        for(long long j=0; j<n; j++)
        {
            for(long long k=j+1; k<n; k++)
            {
                if(v[k]<v[j]) stored[j]++;
            }
        }
        long long ans=0;
        vector<long long> cml;
        for(long long j=0; j<n; j++)
        {
            for(long long k=0; k<j; k++)
            {
                if(v[k]>v[j]) stored[k]--;
            }
            cml.clear();
            cml.push_back(stored[0]);
            for(long long k=1; k<=j; k++) cml.push_back(cml.back()+stored[k]);
            for(long long k=0; k<j; k++)
            {
                if(v[k]<v[j])
                {
                    ans+=cml[j-1]-cml[k];
                }
            }
        }
        cout<<ans<<endl;
    }
}