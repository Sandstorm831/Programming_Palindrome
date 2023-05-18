#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases;i++)
    {
        int n;
        cin>>n;
        vector<int> v;
        for(int j=0; j<n;j++)
        {
            int a;
            cin>>a;
            v.push_back(a);
        }
        if(n%2==1)
        {
            cout<<"Mike"<<endl;
            continue;
        }
        int minm = INT_MAX;
        int indm = 0;
        int minj = INT_MAX;
        int indj = 0;
        for(int j=0; j<n;j++)
        {
            if(j%2==0)
            {
                if(minm == v[j]) continue;
                minm = min(minm, v[j]);
                if(minm == v[j]) indm = j;
            }
            else
            {
                if(minj ==  v[j]) continue;
                minj = min(minj, v[j]);
                if(minj == v[j]) indj = j;
            }
        }
        if(minm>minj)
        {
            cout<<"Mike"<<endl;
            continue;
        }
        else if(minm<minj)
        {
            cout<<"Joe"<<endl;
            continue;
        }
        else{
            if(indm<indj) cout<<"Joe"<<endl;
            else cout<<"Mike"<<endl;
        }
    }
}