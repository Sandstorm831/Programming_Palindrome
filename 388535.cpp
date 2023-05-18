#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> holder(22,vector<int> (2,0));
    for(int i=n; i<=m; i++)
    {
        int x;
        cin>>x;
        for(int j=0; j<=20; ++j, x>>=1 )
        {
            holder[j][x & 1]++;
        }
    }
    int final=0;
    for(int i=0; i<=20; ++i)
    {
        final |= (( holder[i][0] < holder[i][1] ) * ( 1<<i ));
    }
    cout<<final<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}