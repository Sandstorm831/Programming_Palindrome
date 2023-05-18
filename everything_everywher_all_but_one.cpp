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
        int summer=0;
        vector<int> v;
        unordered_set<int> s;
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            summer+=x;
            v.push_back(x);
            s.insert(x);
        }
        bool ans=false;
        for(int j=0; j<v.size(); j++)
        {
            if(double(double(summer-v[j])/double(n-1)) == v[j])
            {
                ans=true;
                break;
            }
        }
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}