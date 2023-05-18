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
        vector<pair<int,int>> p(n, pair<int,int> (0,0));
        for(int j=0; j<n; j++)
        {
            cin>>p[j].first;
        }
        for(int j=0; j<n; j++)
        {
            cin>>p[j].second;
        }
        sort(p.begin(), p.end());
        for(int j=0; j<n; j++)
        {
            if(k>=p[j].first)
            {
                k+=p[j].second;
            }
        }
        cout<<k<<endl;
    }
}