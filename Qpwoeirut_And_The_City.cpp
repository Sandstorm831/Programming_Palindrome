#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0; i<cases;i++)
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
        vector<long long> orig=v;
        long long counter=0;
        long long minn_counter=LLONG_MAX;
        if(n%2 == 1)
        {
            for(long long j=1; j<n; j+=2)
            {
                if(v[j]<=v[j-1])
                {
                    counter += v[j-1]-v[j]+1;
                    v[j] = v[j-1]+1;
                }
                if(v[j]<=v[j+1])
                {
                    counter += v[j+1]-v[j]+1;
                    v[j] = v[j+1]+1;
                }
            }
            cout<<counter<<endl;
            continue;
        }
        else
        {
            vector<long long> floors;
            for(long long j=1; j<n-1; j++)
            {
                long long c = max( v[j-1], v[j+1] )-v[j]+1;
                if(c>=0) floors.push_back(c);
                else floors.push_back(0);
            }
            for(long long j=0; j<floors.size(); j+=2)
            {
                counter+=floors[j];
            }
            minn_counter = counter;
            for(long long j=floors.size()-2; j>=0; j-=2)
            {
                counter +=floors[j+1]-floors[j];
                minn_counter = min(minn_counter, counter);
            }
            cout<<minn_counter<<endl;
        }
    }
}