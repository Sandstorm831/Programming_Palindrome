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
        vector<int> vp;
        vector<int> dr;
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            vp.push_back(a);
        }
        for(int j=0; j<n; j++)
        {
            int b;
            cin>>b;
            dr.push_back(b);
        }
        int minn = INT_MAX;
        int maxx = INT_MIN;
        for(int j=0; j<n; j++)
        {
            minn = min(minn, vp[j]-dr[j]);
            maxx = max(maxx, vp[j]+dr[j]);
        }
        int summ = (minn+maxx);
        if(summ%2 != 0)
        {
            cout<<summ/2<<".5"<<endl;
        }
        else cout<<summ/2<<endl;
    }
}