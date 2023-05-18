#include <bits/stdc++.h>
using namespace std;
vector<long long> vp;
void solve(long long n, long long k)
{
    // cout<<"h";
    if(n==0) return;
    if(n>k)
    {
        if(k>0) vp[k-1]=200;
        vp[k]=-400;
    }
    else
    {
        solve(n-1, k-n);
        vp[n-1]=1000;
    }
    return;
}
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0; i<cases; i++)
    {
        long long n, k;
        cin>>n>>k;
        vp.clear();
        vp.resize(n, -1);
        // cout<<"hh"<<endl;
        solve(n,k);
        for(long long j=0; j<vp.size(); j++) cout<<vp[j]<<" ";
        cout<<endl;
    }
}