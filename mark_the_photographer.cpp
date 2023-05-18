#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n, x;
        cin>>n>>x;
        vector<int> v;
        for(int j=0; j<2*n; j++)
        {
            int a;
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        bool ans=true;
        for(int j=0; j<n; j++)
        {
            if(v[j+n]-v[j]<x)
            {
                ans=false;
                break;
            }
        }
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}