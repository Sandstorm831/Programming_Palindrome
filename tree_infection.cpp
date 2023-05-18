#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n;
        cin>>n;
        vector<int> v(n+1, 0);
        vector<vector<int>> s(n+1, vector<int> ());
        for(int j=2;j<n+1; j++)
        {
            int x;
            cin>>x;
            v[x]++;
            s[x].push_back(j);
        }
        vector<int> layers;
        layers.push_back(1);
        for(int j=0; j<v.size(); j++)
        {
            if(v[j]>0) layers.push_back(v[j]);
        }
        int maxx = INT_MIN;
        sort(layers.begin(), layers.end());
        reverse(layers.begin(), layers.end());
        int tm = layers.size();
        vector<int> clt;
        for(int j=0;j<layers.size(); j++)
        {
            if(layers[j]+j>tm) 
            {
                clt.push_back(layers[j]+j-tm);
                maxx = max(maxx, clt.back());
            }
        }
        while(maxx > 0)
        {
            tm++;
            maxx = INT_MIN;
            int ind=0;
            for(int j=0; j<clt.size(); j++)
            {
                clt[j]--;
                maxx = max(maxx, clt[j]);
                if(maxx == clt[j]) ind = j;
            }
            clt[ind]--;
            maxx = INT_MIN;
            for(int j=0; j<clt.size(); j++) maxx = max(maxx, clt[j]);
        }
        cout<<tm<<endl;
    }
}