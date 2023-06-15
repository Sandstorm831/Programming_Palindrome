#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>> a;
        vector<int> b;
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            a.push_back(make_pair(x,j));
        }
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            b.push_back(x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> v(n);
        for(int j=0; j<n; j++)
        {
            v[a[j].second] = b[j];
        }
        for(int j=0; j<n; j++)
        {
            cout<<v[j]<<" ";
        }
        cout<<endl;
    }
}