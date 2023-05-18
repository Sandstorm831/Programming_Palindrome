#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    int miner = INT_MAX;
    int maxer = INT_MIN;
    // cout<<"her"<<endl;
    for(int j=0; j<n; j++)
    {
        int x;
        cin>>x;
        miner = min(miner, x);
        maxer =  max(maxer, x);
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    cout<<maxer<<" ";
    for(int j=1; j<n-1; j++)
    {
        cout<<v[j]<<" ";
    }
    cout<<miner<<endl;
}