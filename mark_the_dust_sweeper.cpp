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
        vector<long long> a;
        bool s=false;
        long long counter=0;
        for(long long i=0; i<n;i++)
        {
            long long x;
            cin>>x;
            if(x!=0) s=true;
            if(s)
            {
                if(x==0) counter++;
                else counter+=x;
            }
            if(i==n-1)
            {
                if(x==0) counter--;
                else counter-=x;
            }
        }
        // counter-=x;
        long long y = 0;
        cout<<max(y,counter)<<endl;
    }
}