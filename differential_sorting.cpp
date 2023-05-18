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
        long long pos=-1;
        for(long long j=0; j<n; j++)
        {
            long long x;
            cin>>x;
            if(x>=0) pos=j;
            v.push_back(x);
        }
        bool ok=true;
        if(pos!=n-1 && pos!=-1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(pos == -1)
        {
            for(long long j=pos+1; j<n-1; j++)
            {
                if(v[j+1]<v[j])
                {
                    cout<<-1<<endl;
                    ok=false;
                    break;
                }
            }
            if(ok) cout<<0<<endl;
            continue;
        }
        else{
            if(v[pos]<v[pos-1])
            {
                cout<<-1<<endl;
                continue;
            }
            cout<<n-2<<endl;
            for(long long j=0;j<n-2; j++)
            {
                cout<<j+1<<" "<<n-1<<" "<<n<<endl;
            }
        }
    }
}