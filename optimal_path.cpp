#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(long long i=0; i<cases; i++)
    {
        long long n, m;
        cin>>n>>m;
        cout<<(m*(m+1)/2) + ((n*(n+1)/2)-1)*m <<endl; 
    }
}