#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N = 1e5;
    int n, m;
    cin>>n>>m;
    set<long long> colors;
    vector<vector<pair<long long, long long>>> v(N+5, vector<pair<long long, long long>> ());
    for(long long j=0; j<n; j++)
    {
        for(long long k=0; k<m; k++)
        {
            long long x;
            cin>>x;
            colors.insert(x);
            v[x].push_back({j,k});
        }
    }
    long long final=0;
    for(auto itr=colors.begin(); itr!=colors.end(); itr++)
    {
        vector<long long> r;
        vector<long long> c;
        long long clr = *itr;
        for(long long j=0; j<v[clr].size(); j++)
        {
            r.push_back(v[clr][j].first);
            c.push_back(v[clr][j].second);
        }
        sort(r.begin(), r.end());
        sort(c.begin(), c.end());
        for(long long j=0; j<v[clr].size()-1; j++)
        {
            final += (r[j+1]-r[j])*(j+1)*(v[clr].size()-j-1);
            final += (c[j+1]-c[j])*(j+1)*(v[clr].size()-j-1);
        }
    }
    cout<<final<<endl;
}