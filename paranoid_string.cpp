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
        string s;
        cin>>s;
        for(long long j=0; j<n; j++)
        {
            long long x=s[j]-'0';
            v.push_back(x);
        }
        long long counter=0;
        for(long long j=n-1; j>=0; j--)
        {
            if(v[j]!=v[j-1]) counter+=j+1;
            else counter+=1;
        }
        cout<<counter<<endl;
    }
}