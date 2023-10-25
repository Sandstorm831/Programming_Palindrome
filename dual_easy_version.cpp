// Not working, not satisfying the constraints

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;cin>>cases;
    while(cases--)
    {
        int n;cin>>n;vector<int> v(n);
        int pos=0, neg=0;
        for(int i=0; i<n; i++) 
        {
            cin>>v[i];
            if(v[i] > 0) pos++;
            else if(v[i] < 0) neg++;
        }
        vector<pair<int,int>> vp;
        int counter=0;
        if(pos > 0)
        {
            int maxx=INT_MIN;
            int ind=-1;
            for(int i=0; i<v.size(); i++) 
            {
                if(v[i]>maxx)
                {
                    maxx=v[i];
                    ind = i;
                }
            }
            while(v[ind]<=20)
            {
                v[ind]+=v[ind];
                counter++;
                vp.push_back(make_pair(ind+1, ind+1));
            }
            maxx = v[ind];
            for(int i=1; i<v.size(); i++)
            {
                while(v[i-1]> v[i])
                {
                    v[i]+=maxx;
                    counter++;
                    vp.push_back(make_pair(i+1,ind+1));
                    if(v[i] > v[ind])
                    {
                        maxx = v[i];
                        ind = i;
                    }
                }
            }
        }
        else if(pos == 0 && neg>0)
        {
            int minn = INT_MAX;
            int ind = -1;
            for(int i=0; i<v.size(); i++)
            {
                if(v[i] < minn)
                {
                    ind = i;
                    minn = v[i];
                }
            }
            while(v[ind]>=-20)
            {
                v[ind]+=v[ind];
                counter++;
                vp.push_back(make_pair(ind+1, ind+1));
            }
            minn = v[ind];
            for(int i=n-2; i>=0; i--)
            {
                while(v[i]>v[i+1])
                {
                    v[i] += minn;
                    counter++;
                    vp.push_back(make_pair(i+1,ind+1));
                    if(v[i] < minn)
                    {
                        minn = v[i];
                        ind = i;
                    }
                }
            }
        }
        cout<<counter<<endl;
        for(int i=0; i<vp.size(); i++) cout<<vp[i].first<<" "<<vp[i].second<<endl;
    }
}