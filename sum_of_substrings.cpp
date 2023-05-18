#include <bits/stdc++.h>
using namespace std;
long long miner(string s)
{
    long long ones=0;
    for(long long i=0;i<s.length();i++)
    {
        if(s[i]=='1') ones++;
    }
    return 11*(ones-1);
}
int main()
{
    long long cases;
    cin>>cases;
    for(long long j=0; j<cases ;j++)
    {
        long long n, k;
        cin>>n>>k;
        string d;
        cin>>d;
        long long l=0;
        while(d[l]!='1' && l<n) l++;
        if(l==n)
        {
            cout<<0<<endl;
            continue;
        }
        long long t = n-1;
        long long s=0;
        while(d[t]!='1' && t>=0) t--, s++;
        if(s+l==n-1)
        {
            if(k>=s)
            {
                cout<<1<<endl;
                continue;
            }
            else if(k>=l)
            {
                cout<<10<<endl;
                continue;
            }
            else{
                cout<<11<<endl;
                continue;
            }
        }
        if(s+l<=k) cout<<miner(d)<<endl;
        else
        {
            if(k>=s) 
            {
                cout<<miner(d)+1<<endl;
                continue;
            }
            else if(k>=l)
            {
                cout<<miner(d)+10<<endl;
                continue;
            }
            else 
            {
                cout<<miner(d)+11<<endl;
                continue;
            }
        }
    }
}