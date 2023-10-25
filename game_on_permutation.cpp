#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int n;cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++)cin>>v[i];
        int ub = INT_MAX;
        int lb = v[0];
        int counter=0;
        for(int i=1; i<n; i++)
        {
            if(v[i]<ub && v[i]>lb) 
            {
                counter++;
                ub = v[i];
            }
            else if(v[i]<lb) lb = v[i];
        }
        cout<<counter<<endl;
    }
}