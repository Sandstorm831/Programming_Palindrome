#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;cin>>cases;
    while(cases--)
    {
        long long n; cin>>n;
        long long x = 1;
        long long counter=0;
        while(n%x == 0)
        {
            x++;counter++;
        }
        cout<<counter<<endl;
    }
    return 0;
}   