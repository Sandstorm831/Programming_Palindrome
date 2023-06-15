#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n;cin>>n;
        vector<int> a, b;
        unordered_map<int,int> mp, np;
        int aa=-1, bb=-1, na=0, nb=0;
        for(int j=0;j<n; j++)
        {
            int x;cin>>x;
            a.push_back(x);
            if(aa==-1)
            {
                aa=x;
                na=1;
            }
            else if(aa == x)
            {
                na++;
            }
            else if(aa != x)
            {
                if(mp.find(aa)==mp.end())
                {
                    mp[aa]=na;
                    // ump[x]=na;
                }
                else if(mp[aa] < na){
                    mp[aa]=na;
                    // ump[aa]=na;
                }
                aa = x;
                na=1;
            }
        }
        if(mp.find(aa)==mp.end())
        {
            mp[aa]=na;
            // ump[x]=na;
        }
        else if(mp[aa] < na){
            mp[aa]=na;
            // ump[aa]=na;
        }
        for(int j=0; j<n; j++)
        {
            int x;cin>>x;
            b.push_back(x);
            if(bb==-1)
            {
                bb=x;
                nb=1;
            }
            else if(bb == x)
            {
                nb++;
            }
            else if(bb != x)
            {
                if(np.find(bb)==np.end())
                {
                    np[bb]=nb;
                }
                else if(np[bb] < nb) np[bb]=nb;
                bb = x;
                nb = 1;
            }
        }
        if(np.find(bb)==np.end())
        {
            np[bb]=nb;
        }
        else if(np[bb] < nb) np[bb]=nb;
        // int mx = INT_MIN;
        int mdx = INT_MIN;
        for(auto itr = mp.begin(); itr!=mp.end(); itr++)
        {
            if(np.find(itr->first) != np.end())
            {
                mdx = max(mdx, itr->second + np[itr->first]);
                // cout<<itr->first<<" "<<itr->second<<" "<<np[itr->first]<<endl;
            }
            else 
            {
                mdx = max(mdx, itr->second);
                // cout<<" |||| "<<itr->second<<endl;
            }
            // if(mdx<itr->second) mdx = itr->second;
            // cout<<
        }
        for(auto itr = np.begin(); itr != np.end(); itr++)
        {
            if(mp.find(itr->first) == mp.end()) mdx = max(mdx, itr->second);
        }
        cout<<mdx<<endl;
    }
}