#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int n,m;
        cin>>n>>m;
        vector<int> v;
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            v.push_back(a);
        }
        if(m==1)
        {
            if(n%2==0) cout<<n/2-1<<endl;
            else cout<<n/2<<endl;
        }
        else{
            int counter=0;
            for(int j=1; j<n-1; j++)
            {
                if(v[j]>v[j-1]+v[j+1]) counter++;
            }
            cout<<counter<<endl;
        }
    }
}