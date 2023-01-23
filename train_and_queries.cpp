#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int stations, queries;
        cin>>stations>>queries;
        map<int,pair<int,int>> ump;
        for(int j=0; j<stations; j++)
        {
            int station;
            cin>>station;
            if(ump.find(station) == ump.end())
            {
                ump[station].first = j;
                ump[station].second = j;
            }
            else ump[station].second = j;
        }
        for(int j=0; j<queries; j++)
        {
            int q1, q2;
            cin>>q1>>q2;
            if(ump.find(q1) == ump.end() || ump.find(q2) == ump.end() || ump[q1].first > ump[q2].second) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
}