/*
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
        vector<pair<int, int>> hold;
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            hold.push_back(make_pair(a,j));
        }
        sort(hold.begin(), hold.end());
        int base = hold[0].first;
        vector<pair<int, int>> drexel;
        int operations=0;
        for(int j=1; j<n; j++)
        {
            int x = ceil(double(hold[j].first)/(base));
            int diff = x*base-hold[j].first;
            if(diff > 0)
            {
                operations++;
                drexel.push_back(make_pair(hold[j].second+1, diff));
                base = x*base;
            }
        }
        cout<<operations<<endl;
        for(int j=0; j<operations; j++)
        {
            cout<<drexel[j].first<<" "<<drexel[j].second<<endl;
        }
    }
}
*/
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
        int counter=0;
        vector<pair<int,int>> hold;
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            int x = ceil(double(log2(a)));
            if(pow(2,x) > a)
            {
                counter++;
                hold.push_back(make_pair(j, pow(2,x)-a));
            }
        }
        cout<<counter<<endl;
        for(int j=0; j<hold.size(); j++)
        {
            cout<<hold[j].first+1<<" "<<hold[j].second<<endl;
        }
        
    }
}