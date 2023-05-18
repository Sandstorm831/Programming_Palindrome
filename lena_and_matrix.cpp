#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        pair<int,int> a={-1,-1},b={-1,-1},c={-1,-1},d={-1,-1};
        int r;
        int cl;
        cin>>r>>cl;
        vector<string> v;
        for(int j=1; j<=r; j++)
        {
            string s;
            cin>>s;
            v.push_back(s);
            for(int k=1; k<=cl; k++)
            {
                char cd=s[k-1];
                if(cd=='B')
                {
                    if(a.first==-1|| j+k>a.first+a.second) a =  {j,k};
                    if(b.first==-1 || j+k<b.first+b.second) b = {j,k};
                    if(c.first==-1 || j-k>c.first-c.second) c = {j,k};
                    if(d.first==-1 || j-k<d.first-d.second) d = {j,k};
                }
            }
        }
        vector<pair<int,int>> p;
        pair<int,int> opt;
        int ans=INT_MAX;
        p.push_back(a);p.push_back(b); p.push_back(c); p.push_back(d);
        for(int j=1; j<=r; j++)
        {
            for(int k=1; k<=cl; k++)
            {
                int dist=0;
                for(auto it: p) dist=max(dist,abs(j-it.first)+abs(k-it.second));
                if(ans>dist) ans=dist,opt={j,k};
            }
        }
        cout<<opt.first<<" "<<opt.second<<endl;
    }
}