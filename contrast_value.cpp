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
        for(long long j=0;j<n;j++)
        {
            long long x;
            cin>>x;
            v.push_back(x);
        }
        long long counter=0;
        for(long long j=1; j<n-1; j++)
        {
            if((v[j]>=v[j-1] && v[j]<=v[j+1]) || v[j]<=v[j-1] && v[j]>=v[j+1])
            {
                counter++;
                v[j] = v[j-1];
            }
        }
        if(n-counter == 2)
        {
            set<long long> s;
            for(long long j=0;j<n; j++)
            {
                s.insert(v[j]);
            }
            if(s.size() == 1) counter++;
        }
        cout<<n-counter<<endl;
    }
}