#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {
        int ini=-1,fin=-1, n;
        vector<int> v;
        cin>>n;
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            v.push_back(x);
            if(x != j+1 && ini == -1) ini = j;
            else if(ini != -1 && fin == -1 && ini+1 == x) fin = j;
        }
        if(ini == -1 && fin == -1) ini=n-1, fin=n-1;
        for(int j=0; j<ini; j++)
        {
            cout<<v[j]<<" ";
        }
        for(int j=fin; j>=ini; j--)
        {
            cout<<v[j]<<" ";
        }
        for(int j=fin+1; j<n; j++)
        {
            cout<<v[j]<<" ";
        }
        cout<<endl;
    }
}