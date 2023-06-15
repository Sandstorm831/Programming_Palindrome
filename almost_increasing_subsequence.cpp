#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    cin>>n>>q;
    vector<int> v;
    for(int i=0; i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> dump(n,0);
    for(int i=1; i<n-1; i++)
    {
        int pm=0;
        if(v[i]<=v[i-1] && v[i]>=v[i+1]) pm=1; 
        dump[i] = dump[i-1]+pm;
    }
    while(q--)
    {
        int l, r;
        cin>>l>>r;
        if(l==r) cout<<1<<endl;
        else{
            cout<<r-l+1-(dump[r-1-1]-dump[l-1]) <<endl;
        }
    }
}