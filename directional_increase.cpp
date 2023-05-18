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
        for(long long j=0; j<n; j++)
        {
            long long a;
            cin>>a;
            v.push_back(a);
        }
        long long summer=0;
        long long target=0;
        bool now=false;
        for(long long j=0; j<n; j++)
        {
            summer+=v[j];
            if(summer==0)
            {
                now=true;
                continue;
            }
            if(now)
            {
                if(v[j]==0) continue;
                else
                {
                    now=false;
                    break;
                }
            }
            if(summer<0)
            {
                now=false;
                break;
            }
        }
        if(now) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}