#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases; i++)
    {
        int n;
        cin>>n;
        vector<int> v;
        int minn = INT_MAX;
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            v.push_back(a);
            minn = min(a, minn);
        }
        // if(v[0] != minn && v.back() != minn)
        // {
        //     cout<<"No"<<endl;
        // }
        bool s = true;
        int f=0;
        int b=v.size()-1;
        int prev=min(v[0], v.back());
        if(prev ==  v[0]) f++;
        else b--;
        while(s && b-f>=1)
        {
            int kt;
            if(v[f]>v[b])
            {
                kt = v[b];
                b--;
                // prev=kt;
            }
            else
            {
                kt=v[f];
                f++;
                // prev=kt;
            } 
            if(kt>=prev)
            {
                prev = kt;
                continue;
            } 
            else s=false;
        }
        if(s) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}