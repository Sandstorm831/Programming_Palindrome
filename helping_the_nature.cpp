#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0;i<cases; i++)
    {
        long long n;
        cin>>n;
        vector<long long> v;
        for(long long j=0; j<n; j++)
        {
            long long a;
            cin>>a;
            v.push_back(a);
        }
        long long oper=0;
        long long dig=v.back();
        for(long long j=0; j<n-1; j++)
        {
            if(v[j+1]>v[j])
            {
                oper+=v[j+1]-v[j];
                dig-=v[j+1]-v[j];
            }
        }
        for(long long j=n-1; j>0; j--)
        {
            if(v[j-1]>v[j])
            {
                oper+=v[j-1]-v[j];
            }
        }
        oper+=abs(dig);
        cout<<oper<<endl;
    }
}