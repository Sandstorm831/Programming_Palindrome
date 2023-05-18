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
        for(long long j=0; j<n;j++)
        {
            long long x;
            cin>>x;
            v.push_back(x);
        }
        long long a,b;
        bool ans=false;
        vector<long long> vv;
        for(long long j=0; j<n; j++)
        {
            if(ans && j>=n-1) break;
            ans=false;
            // if(j==n) ans=true;
            for(long long k=j+1; k<n; k++)
            {
                // cout<<j<<" -- "<<k<<endl;
                a=j;
                b=k;
                if(v[k]==v[j])
                {
                    ans=true;
                    if(k==n-1) j=n;
                    continue;
                } 
                else if(ans || k-j==1)
                {
                    // cout<<"ger"<<endl;
                    ans=false;
                    if(k-j>1)
                    {
                        // cout<<"der"<<endl;
                        // cout<<k+1<<" ";
                        vv.push_back(k);
                        for(long long l=j; l<k-1; l++)
                        {
                            // cout<<l+1<<" ";
                            vv.push_back(l+1);
                        }
                    }
                    else{
                        // cout<<"mr"<<endl;
                        j=n;
                        break;
                    }
                    j=k-1;
                    break;
                }
            }
        }
        if(ans)
        {
            a++;b++;
            // cout<<b<<" ";
            vv.push_back(b);
            for(long long l=a; l<b; l++)
            {
                // cout<<l<<" ";
                vv.push_back(l);
            }
            for(long long j=0; j<vv.size(); j++)
            {
                cout<<vv[j]<<" ";
            }
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
}