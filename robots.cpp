#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n,m;
        cin>>n>>m;
        vector<string> v;
        for(int j=0; j<n; j++)
        {
            string s;
            cin>>s;
            v.push_back(s);
        }
        int minnr = INT_MAX;
        int minnc = INT_MAX;
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<m; k++)
            {
                if(v[j][k] == 'R')
                {
                    // cout<<j<<" "<<k<<" | "<<endl;
                    minnr = min(minnr, j);
                    minnc = min(minnc,  k);
                    // cout<<minnr<<" "<<minnc<<endl;
                }
            }
        }
        minnr++;
        minnc++;
        bool ans = false;
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<m; k++)
            {
                if(v[j][k] == 'R')
                {
                    // cout<<j<<" "<<k<<" {} "<<endl;
                    if(j<minnr && k<minnc)
                    {
                        ans=true;
                        break;
                    }
                }
            }
        }
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}