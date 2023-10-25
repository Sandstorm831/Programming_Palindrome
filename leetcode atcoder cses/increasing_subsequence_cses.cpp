#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> v(n);for(int i=0; i<n; i++) cin>>v[i];
    vector<int> dump;
    for(int i=0; i<n; i++)
    {
        int index = lower_bound(dump.begin(), dump.end(), v[i]) - dump.begin();
        if(index >= dump.size()) dump.push_back(v[i]);
        else dump[index] = v[i];
    }
    cout<<dump.size();
}