#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0;i<cases;i++)
    {
        int x,k;
        cin>>x>>k;
        vector<int> v;
        for(int j=0; j<x; j++)
        {
            int a;
            cin>>a;
            v.push_back(a);
        }
        int counter=0;
        for(int j=k-1; j>=0; j--)
        {
            if(v[j] > k) counter++;
        }
        cout<<counter<<endl;
    }
}