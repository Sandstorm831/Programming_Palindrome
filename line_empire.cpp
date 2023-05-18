#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0;i<cases; i++)
    {
        long long n, a, b;
        cin>>n>>a>>b;
        vector<long long> v;
        long long cost=0;
        for(long long j=0; j<n; j++)
        {
            long long x;
            cin>>x;
            cost+=x*b;
            v.push_back(x);
        }
        long long prev=0;
        for(long long j=0; j<n; j++)
        {
            long long gradient = (n-j-1)*(v[j]-prev)*b-(v[j]-prev)*a;
            if(gradient > 0) 
            {
                prev = v[j];
                cost -= gradient;
            }
        }
        cout<<cost<<endl;
    }
}