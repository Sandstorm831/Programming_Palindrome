#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases;i++)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> p;
        vector<int> counter(n+1,0);
        vector<int> sad(n+1);
        for(int j=1; j<=n; j++)
        {
            cin>>sad[j];
        }
        for(int j=0; j<m; j++)
        {
            int a,b;
            cin>>a>>b;
            counter[a]++;
            counter[b]++;
            p.push_back(make_pair(a,b));
        }
        if(m%2==0)
        {
            cout<<0<<endl;
            continue;
        }
        int minn_sad=INT_MAX;
        for(int j=0; j<p.size(); j++)
        {
            if(counter[p[j].first]%2==1) minn_sad = min(minn_sad, sad[p[j].first]);
            if(counter[p[j].second]%2==1) minn_sad = min(minn_sad, sad[p[j].second]);
            if(((counter[p[j].first]+counter[p[j].second]))%2==0) minn_sad = min(minn_sad, sad[p[j].first]+sad[p[j].second]);
        }
        cout<<minn_sad<<endl;
    }
}