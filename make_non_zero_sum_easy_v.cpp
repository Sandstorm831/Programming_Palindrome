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
        vector<int> bin;
        int summ=0;
        for(int j=0; j<n; j++){
            int a;
            cin>>a;
            summ +=a;
            bin.push_back(a);
        }
        if(n%2==1)
        {
            cout<<-1<<endl;
            continue;
        }
        summ = summ/2;
        int finder;
        if(abs(summ) == summ) finder = 1;
        else finder = -1;
        summ = abs(summ);
        int prev = 1;
        int succ = 2;
        vector<pair<int,int>> store;
        while(summ > 0)
        {
            if(bin[succ-1] != finder)
            {
                store.push_back(make_pair(prev, succ-1));
                prev = succ;
                succ++;
                continue;
            }
            else
            {
                store.push_back(make_pair(prev, succ));
                prev = succ+1;
                succ +=2;
                summ -=1;
            }
        }
        // cout<<succ<<endl;
        while(prev != n+1)
        {
            store.push_back(make_pair(prev, prev));
            prev++;
        }
        cout<<store.size()<<endl;
        for(int j=0; j<store.size(); j++)
        {
            cout<<store[j].first<<" "<<store[j].second<<endl;
        }
    }
}