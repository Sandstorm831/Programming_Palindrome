#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n,m,r,c;
        cin>>n>>m>>r>>c;
        vector<string> v;
        for(int j=0; j<n; j++)
        {
            string s;
            cin>>s;
            v.push_back(s);
        }
        if(v[r-1][c-1] == 'B')
        {
            cout<<0<<endl;
            continue;
        }
        int ans=-1;
        for(int j=0; j<n; j++)
        {
            if(ans == 1) continue;
            for(int k=0; k<m; k++)
            {
                if(ans == 1) continue;
                if(v[j][k] == 'B')
                {
                    if(j == r-1 || k == c-1)
                    {
                        ans=1;
                    }
                    else ans = 2;
                }
            }
        }
        cout<<ans<<endl;
    }
}