#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> v;
    int summ=0;
    for(int i=0;i<n; i++)
    {
        int x;
        cin>>x;
        summ+=x;
        v.push_back(x);
    }
    for(int i=0; i<q; i++)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int ind; x;
            cin>>ind>>x;
            summ += x-v[ind-1];
            v[ind-1]=x;
        }
        else
        {
            v.clear();
            
        }
    }

}
