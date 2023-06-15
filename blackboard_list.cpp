#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cases;
    cin>>cases;
    while(cases--)
    {
        long long n;
        cin>>n;
        long long maxx = LLONG_MIN;
        long long minn = LLONG_MAX;
        for(long long i=0; i<n; i++)
        {
            long long x; cin>>x;
            maxx = max(maxx, x);
            minn = min(minn, x);
        }
        if(minn < 0) cout<<minn<<endl;
        else cout<<maxx<<endl;

    }
}