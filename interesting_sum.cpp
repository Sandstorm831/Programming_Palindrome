#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases;i++)
    {
        int n;
        cin>>n;
        int maxx=INT_MIN;
        int ind_max=-1;
        int minn = INT_MAX;
        int ind_min=-1;
        vector<int> v;
        for(int j=0;j<n; j++)
        {
            int a;
            cin>>a;
            maxx = max(maxx,a);
            if(maxx == a) ind_max = j;
            minn = min(minn, a);
            if(minn == a) ind_min = j;
            v.push_back(a);
        }
        int maxx_s = INT_MIN;
        int minn_s = INT_MAX;
        for(int j=0; j<n; j++)
        {
            if(j == ind_max || j == ind_min) continue;
            maxx_s = max(maxx_s, v[j]);
            minn_s = min(minn_s, v[j]);
        }
        cout<<maxx+maxx_s-minn-minn_s<<endl;
    }
}