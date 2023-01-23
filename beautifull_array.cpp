#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0;i<cases;i++)
    {
        long long  n,k,b,s;
        cin>>n>>k>>b>>s;
        long long  minl = k*b;
        long long  maxl = (k-1)*n+minl;
        if(s<minl || s>maxl)
        {
            cout<<-1<<endl;
            continue;
        }
        long long diff_b = b;
        long long diff_s = s;
        if(minl+k-1 >=s)
        {
            diff_b = 0;
            diff_s = 0;
            cout<<s<<" ";
        }
        else
        {
            diff_b=0;
            diff_s = s-minl-k+1;
            cout<<minl+k-1<<" ";
        }
        for(long long j=0; j<n-1; j++)
        {
            if(diff_s==0) cout<<0<<" ";
            else
            {
                if(diff_s > k-1)
                {
                    cout<<k-1<<" ";
                    diff_s -= k-1;
                }
                else{
                    cout<<diff_s<<" ";
                    diff_s=0;
                }
            }
        }
        cout<<endl;
    }
}