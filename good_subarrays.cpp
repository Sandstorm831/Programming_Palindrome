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
        vector<int> store;
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            store.push_back(a);
        }
        long long counter=0;
        int k=0;
        for(int j=0; j<n; j++)
        {
            bool s = true;
            for(; k<n; k++)
            {
                if(store[k]>=k-j+1) continue;
                else
                {
                    counter += k-j;
                    s=false;
                    break;
                }
            }
            if(s) counter += k-j;
        }
        cout<<counter<<endl;
    }
}