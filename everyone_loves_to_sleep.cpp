#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n, sh, sm;
        cin>>n>>sh>>sm;
        vector<int> alarms;
        for(int j=0; j<n; j++)
        {
            int h, m;
            cin>>h>>m;
            alarms.push_back(h*60+m);
        }
        int sleep = 60*sh+sm;
        int minn=INT_MAX;
        for(int j=0; j<n; j++)
        {
            if(alarms[j] >= sleep) alarms[j] = alarms[j]-sleep;
            else if(alarms[j]<sleep) alarms[j] = 1440-sleep+alarms[j];
            minn = min(minn, alarms[j]);
        }
        cout<<minn/60<<" "<<minn%60<<endl;
    }
}