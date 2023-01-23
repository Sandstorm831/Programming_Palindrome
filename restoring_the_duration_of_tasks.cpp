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
        vector<int> starters;
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            starters.push_back(a);
        }
        int prev=INT_MIN;
        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            cout<<a-max(starters[j], prev)<<" ";
            prev = a;
        }
        cout<<endl;
    }
}