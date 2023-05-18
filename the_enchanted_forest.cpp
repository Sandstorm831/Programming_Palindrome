#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0;i<cases;i++)
    {
        long long n,s;
        cin>>n>>s;
        if(n>s)
        {
            vector<long long> v;
            for(long long j=0; j<n; j++)
            {
                long long a;
                cin>>a;
                v.push_back(a);
            }
            long long ini=v[0];
            long long summer=0;
            for(long long j=0;j<s;j++)
            {
                summer+=v[j];
            }
            long long maxer=summer;
            for(long long j=s; j<n;j++)
            {
                summer = summer-ini+v[j];
                maxer = max(summer, maxer);
                ini = v[j-s+1];
            }
            maxer+=s*(s-1)/2;
            cout<<maxer<<endl;
            continue;
        }
        else
        {
            long long summer = 0;
            for(long long j=0; j<n;j++)
            {
                long long a;
                cin>>a;
                summer+=a;
            }
            summer += (n*(2*(s-n)+n-1))/2;
            cout<<summer<<endl;
            continue;
        }
    }
}