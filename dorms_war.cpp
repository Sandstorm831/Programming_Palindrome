#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    string k;
    cin>>n>>k;
    int x;
    cin>>x;
    vector<int> v(26,0);
    for(int j=0; j<x; j++)
    {
        char t;
        cin>>t;
        int f = t-'a';
        v[f]=1;
    }
    int maxx = INT_MIN;
    int curr=0;
    for(int j=0; j<k.length(); j++)
    {
        if(v[k[j]-'a']==0) 
        {
            curr++;
            continue;
        }
        else
        {
            maxx = max(maxx, curr);
            curr=1;
            continue;
        }
    }
    cout<<max(maxx, 0)<<endl;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int cases;
    cin>>cases;
    for(int i=0;i<cases; i++)
    {
        solve();
    }
}