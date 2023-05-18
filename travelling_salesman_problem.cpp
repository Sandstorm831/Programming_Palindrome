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
        int min_x=INT_MAX;
        int min_y = INT_MAX;
        int max_x = INT_MIN;
        int max_y = INT_MIN;
        for(int j=0; j<n; j++)
        {
            int x,y;
            cin>>x>>y;
            max_x = max(max_x, max(x,0));
            max_y = max(max_y, max(y,0));
            min_x = min(min_x, min(x,0));
            min_y = min(min_y, min(y,0));
        }
        int ans = 2*abs(max_x-min_x)+2*abs(max_y-min_y);
        cout<<ans<<endl;
    }
}