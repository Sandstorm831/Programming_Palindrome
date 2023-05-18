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
        long long summ=0;
        vector<long long> v;
        for(long long j=0; j<n;j++)
        {
            long long x;
            cin>>x;
            summ +=x;
            v.push_back(x);
        }
        long long ones = summ/n;
        long long zeros = n-ones;
        vector<long long> b(n);
        vector<long long> ans(n,0);
        for(long long j=zeros; j<n ; j++) b[j]=n-1;
        for(long long j=n-1; j>=0; j--)
        {
            long long val = v[j]-(b[j]-j);
            // cout<<v[j]<<endl;
            if(val == j+1) ans[j]=1;
            else if(val == 1)
            {
                ans[j]=0;
                zeros--;
                b[zeros]=j-1;
            }
        }
        for(long long j=0; j<ans.size(); j++)
        {
            cout<<ans[j]<<" ";
        }
        cout<<endl;

    }
}