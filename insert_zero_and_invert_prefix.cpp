#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int n; cin>>n;
        vector<int> v;
        for(int i=0; i<n; i++)
        {
            int x; cin>>x;
            v.push_back(x);
        }
        if(v.back() != 0)
        {
            cout<<"No"<<endl;
            continue;
        }
        else cout<<"Yes"<<endl;
        vector<int> ans;
        int ones=0;
        int zeros=0;
        int store = 0;
        int chpt = 0;
        for(int i=0; i<=n; i++)
        {
            if(i==n)
            {
                ans.push_back(store-chpt);
                for(int j=chpt;j<i-1; j++) ans.push_back(0);
                continue;
            }
            if(i==0 && v[i]==0)
            {
                while(i<n && v[i]!= 1)
                {
                    ans.push_back(0);
                    i++;
                }
                chpt = i;
                if(i==n) continue;
            }
            if(v[i]==0) 
            {
                zeros++;
                if(zeros==1) store=i;
            }
            else if(zeros==0) 
            {
                ones++;
            }
            else
            {
                ans.push_back(store-chpt);
                for(int j=chpt;j<i-1; j++) ans.push_back(0);
                zeros=0;
                ones=1;
                store=-1;
                chpt = i;
            }
        }
        reverse(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}