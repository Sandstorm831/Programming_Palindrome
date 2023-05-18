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
        int maxer=INT_MIN;
        vector<int> a,b;
        for(int i=0; i<2*n; i++)
        {
            int x;
            cin>>x;
            if(i<n) a.push_back(x);
            else b.push_back(x);
            maxer = max(maxer, x);
        }
        int maxx=INT_MIN;
        for(int j=0; j<n; j++)
        {
            // if(a[j] == maxer || b[j] ==  maxer) continue;
            int y = min(a[j], b[j]);
            maxx = max(maxx, y);
        }
        // cout<<maxx<<" "<<maxer<<" | ";
        cout<<maxx*maxer<<endl;
    }
}