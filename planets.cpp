#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases; i++)
    {
        int planets, cost;
        cin>>planets>>cost;
        vector<int> orbits(100,0);
        for(int j=0; j<planets; j++)
        {
            int a;
            cin>>a;
            orbits[a-1]++;
        }
        int coster=0;
        for(int j=0; j<100; j++)
        {
            coster+=min(cost, orbits[j]);
        }
        cout<<coster<<endl;
    }
}