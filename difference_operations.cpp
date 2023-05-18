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
        int x;
        cin>>x;
        vector<int> v;
        bool ans=true;
        for(int j=1; j<n; j++)
        {
            int a;
            cin>>a;
            if(a%x==0) continue;
            else ans=false;
        }
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}