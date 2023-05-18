#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0; i<cases;i++)
    {
        long long n, x, p;
        cin>>n>>x>>p;
        bool y=0;
        for(long long j=1; j<=min(2*n, p); j++)
        {
            // cout<<((j*(j+1))/2)%n<<endl;
            if(((j*(j+1))/2)%n==(n-x)%n)
            {
                y=1;
                break;
            }
        }
        if(y) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}