#include <bits/stdc++.h>
using namespace std;
int main()
{
    long double n; long double t;
    cin>>n>>t;
    int a = (int)n; int b = (int)t;
    long double l = sqrt(n);
    if(a%2 != b%2) cout<<"NO"<<endl;
    else
    {
        if(t > l) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}