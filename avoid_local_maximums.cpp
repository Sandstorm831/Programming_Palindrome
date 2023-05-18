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
        vector<long long> v;
        for(long long j=0; j<n; j++)
        {
            long long x;
            cin>>x;
            v.push_back(x);
        }
        v.push_back(0);
        long long counter=0;
        for(long long j=1; j<n-1; j++)
        {
            if(v[j]>v[j-1] && v[j]>v[j+1]) v[j+1] = max(v[j], v[j+2]), counter++;
        }
        cout<<counter<<endl;
        for(long long j=0; j<n; j++)
        {
            cout<<v[j]<<" ";
        }
        cout<<endl;
    }
}