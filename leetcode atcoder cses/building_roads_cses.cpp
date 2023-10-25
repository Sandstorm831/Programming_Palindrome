#include <bits/stdc++.h>
using namespace std;
int parent(vector<int>& v, int x)
{
    if(v[x] == x) return x;
    else v[x] = parent(v, v[x]);
    return v[x];
}
void unn(vector<int>& v, vector<int>& rank, int x, int y)
{
    int px = parent(v, x);
    int py = parent(v, y);
    if(px == py) return;
    else if(rank[px] > rank[py]) v[py] = px;
    else if(rank[py] > rank[px]) v[px] = py;
    else
    {
        v[px] = py;
        rank[py]++;
    }
}
int main()
{
    int n, m;cin>>n>>m;
    vector<int> v(n+1);
    vector<int> rank(n+1);
    for(int i=0; i<=n; i++) v[i] = i;
    for(int i=0; i<m; i++)
    {
        int x,y;cin>>x>>y;
        unn(v, rank, x, y);
    }
    int counter=0;
    vector<pair<int,int>> vp;
    // for(int i=1; i<v.size(); i++) cout<<v[i]<<" ";
    // cout<<endl;
    for(int i=2; i<=n; i++)
    {
        if(parent(v, 1) != parent(v, i))
        {
            unn(v, rank, 1, i);
            counter++;
            vp.push_back(make_pair(1,i));
            // for(int i=1; i<v.size(); i++) cout<<v[i]<<" ";
            // cout<<endl;
        }
    }
    cout<<counter<<endl;
    for(int i=0; i<vp.size(); i++) cout<<vp[i].first<<" "<<vp[i].second<<endl;
}