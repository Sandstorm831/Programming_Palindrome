#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long cases;
    cin>>cases;
    for(long long i=0; i<cases; i++)
    {
        long long n;
        cin>>n;
        vector<long long> o;
        vector<long long> t;
        string c;
        cin>>c;
        string d;
        cin>>d;
        for(long long j=0; j<n; j++)
        {
            long long a = c[j]-'0';
            // if(a==1) oneso++;
            o.push_back(a);
        }
        for(long long j=0; j<n; j++)
        {
            long long a=d[j]-'0';
            // if(a==1) onest++;
            t.push_back(a);
        }
        if(o[0]!=t[0] || o.back()!=t.back())
        {
            cout<<-1<<endl;
            continue;
        }
        long long co=0;
        long long ct=0;
        long long to=0;
        long long tt=0;
        for(long long j=0; j<n; j++)
        {
            if(to == o[j])
            {
                if(o[j]==0) co++;
                to^=1;
            }
            if(tt == t[j])
            {
                if(t[j]==0) ct++;
                tt^=1;
            }
        }
        if(co!=ct)
        {
            cout<<-1<<endl;
            continue;
        }
        tt=1;
        to=1;
        vector<pair<long long, long long>> om;
        vector<pair<long long, long long>> tr;
        bool oo=false;
        bool ot=false;
        for(long long j=0; j<n; j++)
        {
            if(o[j]==to)
            {
                if(to==1)
                {
                    om.push_back(make_pair(j,n));
                    to=0;
                }
                else
                {
                    om.back().second = j-1;
                    to=1;
                }
            }
            if(t[j]==tt)
            {
                if(tt==1)
                {
                    tr.push_back(make_pair(j,n));
                    tt=0;
                }
                else
                {
                    tr.back().second = j-1;
                    tt=1;
                }
            }
        }
        long long counter=0;
        for(long long j=0; j<om.size(); j++)
        {
            counter+=abs(tr[j].first-om[j].first)+abs(tr[j].second-om[j].second);
        }
        cout<<counter<<endl;
    }
}