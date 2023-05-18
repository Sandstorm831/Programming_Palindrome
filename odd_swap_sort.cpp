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
        vector<long long> srt=v;
        // for(int j=0; j<n; j++) cout<<v[i]<<" | "<<endl;
        bool ans=true;
        sort(srt.begin(), srt.end());
        for(long long j=0; j<n; j++)
        {
            if(v[j] == srt[j]) continue;
            if((v[j]+srt[j])%2 == 0) 
            {
                ans = false;
                break;   
            }
            long long index = lower_bound(v.begin(), v.end(), srt[j]) - v.begin()+1;
            // cout<<index<<" "<<j<<" "<<v[index]<<" "<<v[j]<<" "<<srt[j]<<endl;    
            long long x = v[j];
            v[j] = srt[j];
            v[index] = x;
        }
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}