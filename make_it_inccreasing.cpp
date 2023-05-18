#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    vector<long long> v;
    for(long long i=0; i<n; i++)
    {
        long long x;
        cin>>x;
        v.push_back(x);
    }
    long long minn = LLONG_MAX;
    for(long long i=0; i<n; i++)
    {
        long long orig = i;
        long long counter = 0;
        long long prev=0;
        for(long long j=orig-1; j>=0; j--)
        {
            if(v[j]>prev)
            {
                counter++;
                prev = v[j];
            }
            else
            {
                long long x = prev/v[j];
                x++;
                counter+=x;
                prev = x*v[j];
            }
        }
        prev=0;
        for(long long j=orig+1; j<n; j++)
        {
            if(v[j]>prev)
            {
                counter++;
                prev = v[j];
            }
            else
            {
                long long x = prev/v[j];
                x++;
                counter+=x;
                prev = x*v[j];
            }
        }
        minn = min(minn, counter);
    }
    cout<<minn<<endl;
}