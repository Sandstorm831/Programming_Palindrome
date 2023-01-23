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
        int minn = INT_MAX;
        vector<int> kl;
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            kl.push_back(x);
            minn = min(minn, x);
        }
        int z = 2*minn-1;
        int counter=0;
        for(int j=0; j<n; j++)
        {
            int gh = ceil(double(kl[j])/double(z))-1;
            if (gh<0) gh=0;
            // cout<<ceil(double(kl[j])/double(z))<<endl;
            counter+=gh;
        }
        cout<<counter<<endl;
    }
}