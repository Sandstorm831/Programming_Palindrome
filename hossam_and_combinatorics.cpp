#include <bits/stdc++.h>
using namespace std;
int main()
{
    long cases;
    cin>>cases;
    for(long long i=0; i<cases; i++)
    {
        long long n;
        cin>>n;
        vector<long long>  holder;
        long long minn = INT_MAX,maxx = INT_MIN;
        long long min_counter=0, max_counter=0;
        for(long long j=0; j<n; j++)
        {
            long long l;
            cin>>l;
            minn = min(minn, l);
            maxx = max(maxx, l);
            holder.push_back(l);
        }
        for(long long j=0; j<n; j++)
        {
            if(holder[j] == minn) min_counter++;
            if(holder[j] == maxx) max_counter++;
        }
        if(maxx == minn)
        {
            long long t = min_counter*(max_counter-1);
            cout<<t<<endl;
        }
        else
        {
            long long t = min_counter*max_counter*2;
            cout<<t<<endl;
        }
    }
}