#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,string>>> v(m+1, vector<pair<int,string>> ());
    for(int j=0; j<n; j++)
    {
        string s;
        cin>>s;
        int x;
        cin>>x;
        int sc;
        cin>>sc;
        v[x].push_back(make_pair(sc, s));
    }
    vector<vector<string>> g(m+1, vector<string> ());
    for(int j=1; j<=m; j++)
    {
        int maxer = INT_MIN;
        int index=0;
        for(int i=0; i<v[j].size(); i++)
        {
            maxer = max(maxer, v[j][i].first);
            if(maxer == v[j][i].first) index = i;
        }
        int maxy=INT_MIN;
        for(int i=0; i<v[j].size(); i++)
        {
            if(i != index) maxy = max(maxy, v[j][i].first);
        }
        for(int i=0; i<v[j].size();i++)
        {
            if(v[j][i].first == maxer || v[j][i].first == maxy) g[j].push_back(v[j][i].second);
        }
    }
    for(int j=1; j<=m; j++)
    {
        if(g[j].size() == 2) cout<<g[j][0]<<" "<<g[j][1]<<endl;
        else cout<<"?"<<endl;
    }
}