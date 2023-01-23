#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases;i++)
    {
        string del;
        cin>>del;
        int min_cost = abs(del[0]-del.back());
        int lower = min(del[0], del.back());
        int higher = max(del[0], del.back());
        int max_steps=1;
        vector<pair<int,int>> holder;
        for(int j=0; j<del.size(); j++)
        {
            if(del[j]<=higher && del[j]>=lower) 
            {
                max_steps++;
                holder.push_back(make_pair(del[j],j+1));
            }
            else continue;
        }
        sort(holder.begin(), holder.end());
        if(del[0]>del.back()) reverse(holder.begin(), holder.end());
        cout<<min_cost<<" "<<max_steps-1<<endl;
        cout<<1<<" ";
        for(int j=0; j<holder.size(); j++)
        {
            if(holder[j].second == 1) continue;
            else if(holder[j].second == del.size()) continue;
            cout<<holder[j].second<<" ";
        }
        cout<<del.size()<<endl;
    }
}