#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0; i<cases; i++)
    {
        vector<long long> v;
        long long n,l,r,k;
        cin>>n>>l>>r>>k;
        for(long long j=0; j<n; j++)
        {
            long long x;
            cin>>x;
            if(x>=l && x<=r) v.push_back(x);
        }
        sort(v.begin(), v.end());
        long long counter=0;
        for(long long j=0; j<v.size(); j++)
        {
            if(v[j] <= k) 
            {
                counter++;
                k-=v[j];
            }   
            else break;
        }
        cout<<counter<<endl;
    }
}