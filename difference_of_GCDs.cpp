#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n, l, r;
        cin>>n>>l>>r;
        vector<int> store;
        bool ans=true;
        for(int j=1; j<=n; j++)
        {
            int x = r%j;
            int y = r - x;
            if(y>=l) store.push_back(y);
            else 
            {
                ans = false;
                break;
            }
        }
        if(!ans) cout<<"No"<<endl;
        else
        {
            cout<<"Yes"<<endl;
            for(int j=0; j<store.size(); j++)
            {
                cout<<store[j]<<" ";
            }
            cout<<endl;
        }
    }
}