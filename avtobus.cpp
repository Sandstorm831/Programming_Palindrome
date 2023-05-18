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
        if(n<4) cout<<-1<<endl;
        else if(n%2==1) cout<<-1<<endl;
        else
        {
            long long minn = LLONG_MAX;
            long long maxx = LLONG_MIN;
            long long x = n/4;
            long long y = n/6;
            maxx = x;
            if(n%6 == 0) minn = y;
            else minn = y+1;
            cout<<minn<<" "<<maxx<<endl;
        }
    }
}