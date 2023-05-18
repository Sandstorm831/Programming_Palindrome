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
            long long x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        long long beg = v[0]+v[1];
        long long lst = v.back();
        bool ok=false;
        for(long long j=2; n-j>j; j++)
        {
            if(beg<lst) 
            {
                ok=true;
                break;
            }
            beg+=v[j];
            lst+=v[n-j];
        }
        if(ok || beg<lst) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;  
    }
}