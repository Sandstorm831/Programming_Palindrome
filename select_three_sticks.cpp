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
        vector<int> at;
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            at.push_back(x);
        }
        sort(at.begin(), at.end());
        int minn =  INT_MAX;
        for(int j=0; j<n-2; j++)
        {
            minn = min(minn, at[j+2]-at[j]);
        }
        cout<<minn<<endl;
    }
}