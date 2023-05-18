#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> v;
vector<long long> row;
vector<long long> col;
void solve()
{
    long long r, c, q;
    cin>>r>>c>>q;
    v.resize(r+1, vector<long long> (c+1, 0));
    for(long long i=1; i<=r; i++) for(long long j=1; j<=c; j++) cin>>v[i][j];
    row.resize(r+1);
    col.resize(c+1);
    for(long long j=1; j<=r; j++) row[j]=j;
    for(long long j=1; j<=c; j++) col[j]=j;
    long long x,y,l;char t;
    for(long long i=0; i<q;i++)
    {
        cin>>t>>x>>y;
        if(t == 'g') cout<<v[row[x]][col[y]]<<endl;
        else if(t == 'r') l = row[x],row[x] = row[y],row[y] = l;
        else if(t == 'c') l = col[x], col[x] = col[y], col[y] = l;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
}