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
        vector<long long> s;
        for(long long j=0; j<n; j++)
        {
            long long x;
            cin>>x;
            s.push_back(x);
        }  
        if(n%2==1)
        {
            cout<<"No"<<endl;
            continue;
        }
        sort(s.begin(), s.end());
        bool ans=true;
        for(long long j=1; j<(n/2); j++)
        {
            if(s[j+(n/2)-1] <= s[j])
            {
                ans=false;
                break;
            }
        }
        if(!ans)
        {
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
        for(long long j=0; j<n/2; j++)
        {
            cout<<s[j]<<" "<<s[j+n/2]<<" ";
        }
        cout<<endl;
    }
}