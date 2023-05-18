#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0; i<cases; i++)
    {
        long long n;
        cin>>n;
        vector<long long> a, b;
        for(long long j=0; j<n; j++)
        {
            long long x;
            cin>>x;
            a.push_back(x);
        }
        for(long long j=0; j<n; j++)
        {
            long long x; 
            cin>>x;
            b.push_back(x);
        }
        long long k=n-1, num=0;
        vector<long long> c(n, 0);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(long long j=n-1; j>=0; j--)
        {
            long long val = b[j];
            if(k<0)
            {
                c[j] = n;
                continue;
            }
            for(; k>=0; k--)
            {
                if(val<a[k]) num++;
                else
                {
                    c[j]=num;
                    // k++; //---------------------
                    break;
                }
            }
            if(k<0)
            {
                c[j] = n;
                continue;
            }
        }
        long long ans = 1;
        long long ded=0;
        for(long long j=n-1; j>=0; j--)
        {
            // cout<<ans<<" "<<c[j]<<endl;
            ans = (ans%mod * (c[j]+ded)%mod)%mod;
            ded--;
        }
        cout<<ans<<endl;
    }
}