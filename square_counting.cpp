#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0; i<cases; i++)
    {
        long long n, s;
        cin>>n>>s;
        cout<<s/(n*n)<<endl;
    }
}