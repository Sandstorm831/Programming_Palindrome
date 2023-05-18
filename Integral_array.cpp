#include <bits/stdc++.h>
using namespace std;
void solve()
{

    int n,c;
    cin>>n>>c;
    vector<int> v;
    vector<bool> exist(c+1, false);
    v.push_back(0);
    for(int j=0; j<n; j++)
    {
        int x;
        cin>>x;
        v.push_back(x);
        exist[x] = true;
    }
    sort(v.begin(), v.end());
    bool ver=true;
    for(int j=1; j<=n && ver; j++)
    {
        int k=j;
        while(k<=n && ver)
        {
            if(!exist[v[k]/v[j]]) ver=false;
            int nxt = (v[k]/v[j]+1)*v[j];
            k = lower_bound(v.begin(), v.end(), nxt) - v.begin();
        }
    }
    if(ver) cout<<"Yes"<<endl;
    else cout<<"NO"<<endl;

}
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t; cin >> t;
  while (t--) solve();
}